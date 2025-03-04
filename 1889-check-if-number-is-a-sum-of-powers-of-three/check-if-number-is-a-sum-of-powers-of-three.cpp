class Solution {
public:
    bool checkPowersOfThree(int n) {
        int rem = 0;
        int m = n;
        while(m) {
            if(m%3 == 2) {
                return 0;
            }
            m /= 3;
        }

        return 1;
    }
};