class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> um;
        int n = mat.size();
        int m = mat[0].size();

        int len = n * m;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                um[mat[i][j]] = {i,j};
            }
        }

        vector<int> row(n, 0), col(m, 0);

        for(int k=0; k<len; k++) {
            int num = arr[k];
            int x = um[num].first;
            int y = um[num].second;

            row[x] += 1;
            col[y] += 1;

            cout << row[x] << " " << col[y] << endl;

            if(row[x]==m || col[y]==n)
                return k;
        }
        return 0;
    }
};