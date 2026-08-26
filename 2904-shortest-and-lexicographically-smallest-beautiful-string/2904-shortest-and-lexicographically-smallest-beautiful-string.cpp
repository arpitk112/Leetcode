class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        int ones = 0;
        string ans = "";

        for(int j = 0; j<n; j++){
            if(s[j] == '1'){
                ones++;
            }

            while(ones > k){
                if(s[i] == '1'){
                    ones--;
                }
                i++;
            }

            while(ones == k && i <= j && s[i] == '0'){
                i++;
            }

            if(ones == k){
                string curr = s.substr(i,j-i+1);

                if(ans.size() == 0 || curr.size() < ans.size() || curr.size() == ans.size() && curr < ans){
                    ans = curr;
                }
            }
            
        }
        return ans;
    }
};