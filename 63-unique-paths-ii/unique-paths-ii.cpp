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
        }
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return count_ways(0, 0, m, n, obs, dp);
        // vector<int> prev(m,0);
        // for(int i=0; i<m; i++) {
        //     vector<int> curr(n, 0);
        //     for(int j=0; j<n; j++) {
        //         if(i==0 && j==0) curr[j] = 1;
        //         else {
        //             int up = 0;
        //             int left = 0;
        //             if(i>0) up = prev[j];
        //             if(j>0) left = curr[j-1];
        //             curr[j] = up + left;
        //         }
        //     }
        //     prev = curr;
        // }
        // return prev[n-1];
    }
};