class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int row = 0; row<rows; row++) {
            for(int col=1; col<cols; col++) {
                matrix[row][col] += matrix[row][col-1];
            }
        }

        int count = 0;

        for(int col1=0; col1<cols; col1++) {
            for(int col2 = col1; col2<cols; col2++) {
                unordered_map<int,int> um;

                um[0] = 1;
                int sum = 0;

                for(int row=0; row<rows; row++) {
                    sum += matrix[row][col2] - (col1>0 ? matrix[row][col1-1]:0);
                    count += um[sum-target];
                    um[sum]++;
                }
            }
        }

        return count;
    }
};