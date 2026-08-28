class Solution {
public:
    char oddChar = '$';
    string result = "";

    bool solve(string &curr, vector<int>&freq, string target, bool isGreater, int i){
        if(curr.size() == target.size()/2){
            string candidate = curr;
            string rightHalf = curr;
            reverse(rightHalf.begin(),rightHalf.end());

            if(oddChar != '$'){
                candidate += oddChar;
            }

            candidate += rightHalf;

            if(candidate > target){
                result = candidate;
                return true;
            }
            return false;
        }


        for(char ch = 'a'; ch <= 'z'; ch++){
            if(freq[ch - 'a'] == 0) continue;

            if(!isGreater && ch < target[i]){
                continue;
            }

            curr.push_back(ch);
            freq[ch - 'a']--;

            bool greater = isGreater || ch > target[i];

            if(solve(curr,freq,target,greater,i+1)){
                return true;
            }

            curr.pop_back();
            freq[ch - 'a']++;
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        int oddCount = 0;
        vector<int>freq(26,0);

        for(char &x : s){
            freq[x - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] % 2 == 1) {
                oddCount++;
                oddChar = i + 'a';
            }
        }

        if(oddCount > 1) return "";

        for(int &x : freq){
            x /= 2;
        }

        int halfLen = n / 2;

        string curr;

        return solve(curr,freq,target,false,0) ? result : "";
    }
};