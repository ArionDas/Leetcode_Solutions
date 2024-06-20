class Solution {
public:
    // int count_ways(int a, int b, int m, int n, vector<vector<int>> &dp) {
    //     if(a==m-1 && b==n-1) {
    //         return 1;
    //     }
    //     if(dp[a][b] != -1) return dp[a][b];
    //     int ways = 0;
    //     if(a+1<m) {
    //         ways += count_ways(a+1, b, m, n, dp);
    //     }
    //     if(b+1<n) {
    //         ways += count_ways(a, b+1, m, n, dp);
    //     }

    //     return dp[a][b] = ways;
    // }
    int uniquePaths(int m, int n) {
        vector<int> prev(m,0);
        for(int i=0; i<m; i++) {
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++) {
                if(i==0 && j==0) curr[j] = 1;
                else {
                    int up = 0;
                    int left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};