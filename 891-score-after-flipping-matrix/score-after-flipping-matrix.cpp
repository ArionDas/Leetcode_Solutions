class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++) {
            if(grid[i][0]==0) {
                for(int j=0; j<m; j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        for(int j=1; j<m; j++) {
            int count=0;

            for(int i=0; i<n; i++) {
                if(grid[i][j])
                    count += 1;
            }

            if(count*2 >= n)
                continue;

            else {
                for(int i=0; i<n; i++)
                    grid[i][j] = !grid[i][j];
            }
        }

        int ans = 0;

        for(int i=0; i<n; i++) {
            int power = 0;
            for(int j=m-1; j>=0; j--) {
                ans += grid[i][j] * pow(2,power++);
            }
        }

        return ans;
    }
};