class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]==1) {
                    int count = 0;
                    for(int k=0; k<n; k++) {
                        if(mat[k][j]==1)
                            count += 1;
                    }
                    if(count>1)
                        break;
                    count = 0;
                    for(int k=0; k<m; k++) {
                        if(mat[i][k]==1)
                            count += 1;
                    }
                    if(count>1)
                        break;
                    ans += 1;
                }
            }
        }
        return ans;
    }
};