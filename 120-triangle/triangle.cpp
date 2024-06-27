class Solution {
public:

    // int find_min_path_sum(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];

    //     if(i==n-1) {
    //         return triangle[i][j];
    //     }

    //     int bottom = find_min_path_sum(i+1, j, n, triangle, dp);
    //     int right = find_min_path_sum(i+1, j+1, n, triangle, dp);

    //     return dp[i][j] = min(bottom, right) + triangle[i][j];
    // }

    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<int> prev(n,0);

        for(int j=0; j<n; j++) {
            prev[j] = tri[n-1][j];
        }

        for(int i=n-2; i>=0; i--) {
            vector<int> curr(n,0);

            for(int j=i; j>=0; j--) {
                int down = tri[i][j] + prev[j];
                int diagonal = tri[i][j] + prev[j+1];
                curr[j] = min(down, diagonal);
            }
            prev = curr;
        }

        return prev[0];
    }
};