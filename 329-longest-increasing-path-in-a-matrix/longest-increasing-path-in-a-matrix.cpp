class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> dp;
    int n;
    int m;
    int maxPath;
    // int dfs(int pi, int pj, int i, int j, int n, int m, vector<vector<int>>& matrix, vector<vector<int>> &info) {
    //     if(info[i][j] != -1)
    //         return info[i][j];

    //     int ans_ = 0;

    //     for(int i=0; i<4; i++) {
    //         int nx = i+dx[i];
    //         int ny = j+dy[i];

    //         if(nx>=0 && nx<n && ny>=0 && ny<m && matrix[i][j]<matrix[nx][ny] && ) {
    //             ans_ = max(ans_, dfs(nx, ny, n, m, matrix, info)+1); 
    //         }
    //     }
    //     return info[i][j] = ans_;
    // }

    int solve(vector<vector<int>>& matrix, int n, int m, int i, int j) {
        //int MAX = 1;
        if(dp[i][j])
            return dp[i][j];
        dp[i][j] = 1;
        for(int k=0; k<4; k++) {
            int nx = i+dx[k];
            int ny = j+dy[k];

            if(nx<0 || ny<0 || nx>=n || ny>=m || matrix[nx][ny] <= matrix[i][j])
                continue;

            dp[i][j] = max(dp[i][j], 1 + solve(matrix, n, m, nx, ny));
        }

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        maxPath = 0;

        dp.resize(n, vector<int>(m, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                maxPath = max(maxPath, solve(matrix, n, m, i, j));
            }
        }
        return maxPath;
    }
};