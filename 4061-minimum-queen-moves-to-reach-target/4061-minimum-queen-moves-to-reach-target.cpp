class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int s1 = source[0];
        int s2 = source[1];
        int t1 = target[0];
        int t2 = target[1];

        if(s1 == t1 && s2 == t2) return 0;

        if(abs(s1-t1) == abs(s2-t2)){
            return 1;
        }
        if(s1 == t1 || s2 == t2){
            return 1;
        }

        return 2;
    }
};