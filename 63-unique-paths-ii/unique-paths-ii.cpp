class Solution {
public:

    int count_ways(int a, int b, int m, int n, vector<vector<int>>& obs, vector<vector<int>> &dp) {
        if(a==m-1 && b==n-1) {
            return 1;
        }
        if(obs[a][b]==1) return dp[a][b] = 0;
        if(dp[a][b] != -1) return dp[a][b];
        int ways = 0;
        if(a+1<m && obs[a+1][b]==0) {
            ways += count_ways(a+1, b, m, n, obs, dp);
        }
        if(b+1<n && obs[a][b+1]==0) {
            ways += count_ways(a, b+1, m, n, obs, dp);
        }

        return dp[a][b] = ways;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size();
        int n = obs[0].size();

        if(m==1 && n==1) {
            if(obs[0][0]==1)
                return 0;
            else
                return 1;
        }
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = count_ways(0, 0, m, n, obs, dp);
        return ans;
    }
};