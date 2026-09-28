class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = INT_MIN;
        int currDepth = 0;

        for(char c : s){
            if(c == '('){
                currDepth++;
                maxDepth = max(maxDepth,currDepth);
            }else if(c == ')'){
                currDepth--;
            }
        }
        return (maxDepth == INT_MIN) ? 0 : maxDepth;
    }
};