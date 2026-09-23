class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int i=0;
        int j=0;

        int currSum = 0;

        int totSum = accumulate(nums.begin(), nums.end(), 0);

        int ans = -1;
        while(j<n){
            currSum += nums[j];

            while(i<=j && currSum > totSum-x){
                currSum -= nums[i];
                i++;
            }

            if(currSum==totSum-x) ans = max(ans, j-i+1);
            j++;
        }

        if(ans==-1) return -1;
        return n-ans;        
    }
};