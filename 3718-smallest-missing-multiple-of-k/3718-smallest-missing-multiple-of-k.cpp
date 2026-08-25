class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(int num : nums){
            mp[num]++;
        }

        for(int i = k; i<=10000; i += k){
            if(mp.find(i) == mp.end()){
                return i;
            }
        }

        return 0;
    }
};