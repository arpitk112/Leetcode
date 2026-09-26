class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sum_source = 0;
        long long sum_target = 0;
        
        for(long long x: source){
            sum_source += x;
        }
        
        for(long long x: target){
            sum_target += x;
        }

        if(sum_source == sum_target) return true;

        return false;
    }
};