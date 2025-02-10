class Solution {
public:

    bool check_string(string &s) {
        int len = s.length();
        int i = 0;
        bool f = 1;
        bool z = 0;
        while(i<len) {
            char ch = s[i];
            if(ch == '2' || ch == '5' || ch == '6' || ch == '9') { z = 1;}
            if(ch == '3' || ch == '4' || ch == '7')
                return 0;
            i += 1;
        }

        return z;
    }

    int rotatedDigits(int n) {

        if(n == 1)
            return 0;

        if(n == 2)
            return 1;

        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 0;
        dp[2] = 1;

        int k = 3;
        while(k <= n) {
            string str = to_string(k);
            if(check_string(str))
                dp[k] = dp[k-1] + 1;
            else {
                dp[k] = dp[k-1];
            }

            k += 1;
        }

        return dp[n];
    }
};