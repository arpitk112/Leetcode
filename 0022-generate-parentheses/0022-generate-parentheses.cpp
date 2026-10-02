class Solution {
public:
    vector<string> result;
    void insertParen(string& valid, int n, int open, int close) {
        if (valid.size() == 2 * n) {
            result.push_back(valid);
            return;
        }

        if(open < n){
            valid.push_back('(');
            insertParen(valid, n, open+1, close);
            valid.pop_back();
        }
    
        if(close < open){
            valid.push_back(')');
            insertParen(valid, n, open, close+1);
            valid.pop_back();
        }
        
    }

    vector<string> generateParenthesis(int n) {
        string valid = "";
        int open = 0;
        int close = 0;

        insertParen(valid, n, open, close);

        return result;
    }
};