class Solution {
public:

    int find_min_path_sum(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(i==n-1) {
            return triangle[i][j];
        }

        int bottom = find_min_path_sum(i+1, j, n, triangle, dp);
        int right = find_min_path_sum(i+1, j+1, n, triangle, dp);

        return dp[i][j] = min(bottom, right) + triangle[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));

        return find_min_path_sum(0, 0, n, triangle, dp);
    }
};