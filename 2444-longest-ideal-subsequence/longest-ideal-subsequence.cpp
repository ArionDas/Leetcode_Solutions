class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26,0);
        int res=0,cur;

        for(int i=0; i<s.length(); i++) {
            cur = s[i] - 'a';
            dp[cur] += 1;

            for(int j=max(0, cur-k); j<=min(25, cur+k); j++) {
                if(j!=cur)
                    dp[cur] = max(dp[j]+1, dp[cur]);
            }
            res = max(res, dp[cur]);
        }
        return res;
    }
};