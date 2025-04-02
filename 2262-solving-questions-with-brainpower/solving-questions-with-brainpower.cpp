class Solution {
public:
    long long mostPoints(vector<vector<int>>& qs) {
        int n = qs.size();
        vector<long long> dp(n+1, 0);

        for(int i=n-1; i>=0; i--) {
            int pts = qs[i][0];
            int bp = qs[i][1];
            int next = i + bp + 1;

            long long take = pts + (next<n? dp[next]:0);
            long long skip = dp[i+1];

            dp[i] = max(take, skip);
        }

        return dp[0];
    }
};