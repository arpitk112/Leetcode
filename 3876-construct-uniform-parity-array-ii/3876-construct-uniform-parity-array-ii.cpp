class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        bool ans = true;

        vector<int>odd;
        vector<int>even;

        for(int num : nums1){
            if(num % 2 == 0){
                even.push_back(num);
            }else{
                odd.push_back(num);
            }
        }
        // [5,13] [6]

        for(int e : even){
            for(int o : odd){
                if(e - o >= 1){
                    break;
                }else{
                    ans = false;
                    break;
                }
            }
        }
        cout << ans;
        // if(odd.size() > 0 && even.size() > 0) return  false;
        return ans && true;
    }
};