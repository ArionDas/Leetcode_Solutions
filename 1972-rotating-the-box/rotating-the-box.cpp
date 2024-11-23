class Solution {
public:

    vector<vector<char>> rotate(int n, int m, vector<vector<char>>& box) {
        vector<vector<char>> res(m, vector<char>(n, '.'));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                res[j][n-i-1] = box[i][j];
            }
        }
        return res;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++) {
            for(int j=m-1; j>=0; j--) {
                if(box[i][j] == '#') {
                    box[i][j] = '.';
                    int k = j;
                    while(k<m) {
                        if(box[i][k]=='.') {
                            k++;
                        }
                        else {
                            box[i][k-1] = '#';
                            break;
                        }
                    }
                    if(k==m) {
                        box[i][m-1] = '#';
                    }
                }
            }
        }

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<m; j++) {
        //         cout << box[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        vector<vector<char>> ans = rotate(n, m, box);

        return ans;
    }
};