class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<int> onerow(row,0);
        vector<int> onecol(col,0);

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                onerow[i] += grid[i][j];
                onecol[j] += grid[i][j];
            }
        }
        
        vector<vector<int>> ans(row, vector<int>(col,0));
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                cout << i << " " << j << endl;
                ans[i][j] = onerow[i] + onecol[j] - (row-onerow[i]) - (col-onecol[j]);
            }
        }
        return ans;
    }
};