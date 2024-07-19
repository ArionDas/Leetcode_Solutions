class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board) {
        vis[row][col] = 1;

        int n = board.size();
        int m = board[0].size();

        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++) {
            int nrow = row + del_row[i];
            int ncol = col + del_col[i];

            if(nrow >= 0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1 && board[nrow][ncol]=='O') {
                dfs(nrow, ncol, vis, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int j=0; j<m; j++) {
            if(board[0][j]=='O' && vis[0][j]!=1) {
                dfs(0,j, vis, board);
            }
            if(board[n-1][j]=='O' && vis[n-1][j]!=1) {
                dfs(n-1,j, vis, board);
            }
        }

        for(int i=0; i<n; i++) {
            if(board[i][0]=='O' && vis[i][0]!=1) {
                dfs(i,0, vis, board);
            }
            if(board[i][m-1]=='O' && vis[i][m-1]!=1) {
                dfs(i,m-1, vis, board);
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j]!=1 && board[i][j]=='O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};