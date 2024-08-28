class Solution {
public:

    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    void check_sub_island(int row, int col, int n, int m, vector<vector<bool>> &visited, vector<vector<int>>& grid1, vector<vector<int>>& grid2, bool& val) {
        
        stack<pair<int,int>> stp;
        stp.push({row, col});

        while(!stp.empty()) {
            pair<int,int> land = stp.top();
            stp.pop();
            int r = land.first;
            int c = land.second;
            visited[r][c] = 1;
            //cout << r << " " << c << endl;
            if(grid1[r][c]!=1) {
                val = 0;
            }
            for(int d=0; d<4; d++) {
                    int new_row = r + dr[d];
                    int new_col = c + dc[d];
                    //cout << new_row << " " << new_col << endl;
                    if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && grid2[new_row][new_col]==1 && !visited[new_row][new_col]) {
                        stp.push({new_row, new_col});
                    }
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        int count = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!visited[i][j]) {
                    //cout << "new_island" << endl;
                    bool val = 1;
                    if(grid2[i][j]==1) {
                        check_sub_island(i, j, n, m, visited, grid1, grid2, val);
                    if(val)
                        count += 1;
                    }
                }
                }
            }
        return count;
    }
};