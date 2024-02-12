class Solution {
public:

    int count_ways(int a, int b, int m, int n, vector<vector<int>> &dp) {
        if(a==m-1 && b==n-1) {
            return 1;
        }
        if(dp[a][b] != -1) return dp[a][b];
        int ways = 0;
        if(a+1<m) {
            ways += count_ways(a+1, b, m, n, dp);
        }
        if(b+1<n) {
            ways += count_ways(a, b+1, m, n, dp);
        }

        return dp[a][b] = ways;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = count_ways(0, 0, m, n, dp);
        return ans;
    }
};