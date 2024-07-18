class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&ans, vector<vector<int>>& image, int new_color, int ini_color) {
        ans[row][col] = new_color;
        int n = image.size();
        int m = image[0].size();

        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++) {
            int nrow = row + del_row[i];
            int ncol = col + del_col[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == ini_color && ans[nrow][ncol]!=new_color) {
                dfs(nrow, ncol, ans, image, new_color, ini_color);
            }
        }
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini_color = image[sr][sc];

        vector<vector<int>> ans = image;

        dfs(sr, sc, ans, image, color, ini_color);

        return ans;
    }
};