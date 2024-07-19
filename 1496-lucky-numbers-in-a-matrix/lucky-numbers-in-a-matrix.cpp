class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row_min(n,0);
        vector<int> col_max(m,0);

        for(int i=0; i<n; i++) {
            int mini = INT_MAX;
            for(int j=0; j<m; j++) {
                mini = min(matrix[i][j], mini);
            }
            row_min[i] = mini;
        }

        for(int j=0; j<m; j++) {
            int maxi = INT_MIN;
            for(int i=0; i<n; i++) {
                maxi = max(maxi, matrix[i][j]);
            }
            col_max[j] = maxi;
        }

        vector<int> ans;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == col_max[j] && matrix[i][j] == row_min[i]) {
                    ans.push_back(matrix[i][j]);
                    break;
                }
            }
        }

        return ans;
    }
};