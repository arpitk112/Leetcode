/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void solve(ListNode* prev, ListNode* head, int i,
               vector<int>& criticalPoints) {
        if (!head || !head->next) {
            return;
        }

        ListNode* next = head->next;

        int prevVal = prev->val;
        int currVal = head->val;
        int nextVal = next->val;

        if (currVal < prevVal && currVal < nextVal ||
            currVal > prevVal && currVal > nextVal) {
            criticalPoints.push_back(i);
        }

        solve(head, head->next, i + 1, criticalPoints);
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;

        vector<int> criticalPoints;

        solve(prev, head->next, 2, criticalPoints);
        int minDistance = INT_MAX;

        if (criticalPoints.size() < 2) {
            return {-1,-1};
        }

        for(int i = 1; i<criticalPoints.size(); i++){
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i-1]);
        }

        int maxDistance = criticalPoints.back() - criticalPoints.front();

        return {minDistance, maxDistance};
    }
};