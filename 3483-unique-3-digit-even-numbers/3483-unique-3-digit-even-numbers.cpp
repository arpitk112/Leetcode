class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int>st;

        for(int k = 0; k < n; k++){
            if(digits[k] % 2 == 0){
                for(int i = 0; i < n; i++){
                    if(i != k && digits[i] != 0){
                        for(int j = 0; j<n; j++){
                            if(i != j && j != k){
                                st.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                            }
                        }
                    }
                }
            }
        }
        return st.size();
    }
};