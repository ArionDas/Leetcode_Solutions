class Solution {
public:

    int find_max_moves(int x, int y, vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp) {
        //cout << x << " " << y << endl;
        if(x>=n || y>=m || x<0 || y<0)
            return 0;
        if(dp[x][y] != -1)
            return dp[x][y];

        int max_moves = 0;
        int dx[] = {-1, 0, 1};
        int dy[] = {1, 1, 1};

        for(int i=0; i<3; i++) {
            int new_row = x + dx[i];
            int new_col = y + dy[i];

            if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] > grid[x][y]) {
                //cout << grid[new_row][new_col] << endl;
                max_moves = max(max_moves, find_max_moves(new_row, new_col, grid, n, m, dp) + 1);
            }
        }

        return dp[x][y] = max_moves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int max_moves = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        for(int i=0; i<n; i++) {
            //cout << "new" << endl;
            max_moves = max(max_moves, find_max_moves(i, 0, grid, n, m, dp));
        }

        return max_moves;
    }
};