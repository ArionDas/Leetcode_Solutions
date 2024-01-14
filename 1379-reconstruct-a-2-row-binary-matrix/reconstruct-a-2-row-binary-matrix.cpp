class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int len = colsum.size();
        bool flag = 1;
        vector<vector<int>> ans(2, vector<int>(len,0));

        for(int i=0; i<len; i++) {
            if(colsum[i]==2) {
                if(upper>0 && lower>0) {
                    ans[0][i] = ans[1][i] = 1;
                    upper -= 1;
                    lower -= 1;
                }
                else {
                    flag = 0;
                    break;
                }
            }
            else if(colsum[i]==1) {
                if(upper>0 || lower>0) {
                    if(upper>=lower) {
                        ans[0][i] = 1;
                        upper -= 1;
                    }
                    else {
                        ans[1][i] = 1;
                        lower -= 1;
                    }
                }
                else {
                    flag = 0;
                    break;
                }
            }
            else {
                continue;
            }
        }

        if(!flag || !(upper==0 && lower==0)) {
            vector<vector<int>> ans2;
            return ans2;
        }
        return ans;
    }
};