class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int> res(2,0);

        for(int i = 0; i<nums.size(); i++){
            int result = target - nums[i];

            if(mp.find(result) != mp.end()){
                res[0] = mp[result];
                res[1] = i;
                break;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};