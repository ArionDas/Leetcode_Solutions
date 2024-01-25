class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int text1_len = text1.length();
        int text2_len = text2.length();

        vector<vector<int>> dp(text1_len+1, vector(text2_len+1, 0));
        //int dp[text1_len+1][text2_len+1]={0};

        for(int i=1; i<=text1_len; i++) {
            for(int j=1; j<=text2_len; j++) {
                if(text1[i-1]==text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[text1_len][text2_len];
    }
};