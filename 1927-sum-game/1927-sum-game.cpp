class Solution {
public:
    bool sumGame(string num) {
        int leftSum = 0;
        int rightSum = 0;
        int cLeft = 0;
        int cRht = 0;

        int n = num.size();

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                cLeft++;
            else{
                leftSum += num[i] - '0';
            }
            
        }
        for (int i = n/2; i < n; i++) {
            if (num[i] == '?')
                cRht++;
            else{
                rightSum += num[i] - '0';
            }   
        }

        return (leftSum - rightSum) * 2 != (cRht - cLeft) * 9;
    }
};