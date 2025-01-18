class Solution {
public:

    int falling_forever_dua_lipa(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if(i==n)
            return j;

        if(j==m)
            return -1;

        if(grid[i][j] == 1) {
            if(j+1<m && grid[i][j+1] == 1) {
                return falling_forever_dua_lipa(i+1, j+1, n, m, grid);
            }
            else return -1;
        }
        else {
            if(j-1>=0 && grid[i][j-1] == -1) {
                return falling_forever_dua_lipa(i+1, j-1, n, m, grid);
            }
            else return -1;
        }
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<m; i++) {
            int col = falling_forever_dua_lipa(0, i, n, m, grid);
            ans.push_back(col);
        }

        return ans;
    }
};