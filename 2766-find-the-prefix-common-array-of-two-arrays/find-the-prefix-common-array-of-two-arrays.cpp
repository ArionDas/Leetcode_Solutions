class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        vector<int> f(52, 0);
        int n = a.size();

        vector<int> ans;

        for(int i=0; i<n; i++) {
            f[a[i]]++;
            f[b[i]]++;
            int cnt = 0;
            for(int j=0; j<=n; j++) {
                if(f[j] != 0 && f[j]%2==0) {
                    cnt += 1;
                }
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};