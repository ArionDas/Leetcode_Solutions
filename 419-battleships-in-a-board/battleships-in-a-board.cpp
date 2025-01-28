class Solution {
public:

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};

    void dfs(int i, int j, int n, int m, vector<vector<bool>> &vis, vector<vector<char>>& grid) {

        vis[i][j] = 1;
        int ans = 0;
        for(int k=0; k<4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny] == 'X') {
                dfs(nx, ny, n, m, vis, grid);
            }
        }

        return;
    }

    int countBattleships(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, 0));

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 'X' && !vis[i][j]) {
                    ans += 1;
                    dfs(i, j, n, m, vis, grid);
                }
            }
        }

        return ans;
    }
};