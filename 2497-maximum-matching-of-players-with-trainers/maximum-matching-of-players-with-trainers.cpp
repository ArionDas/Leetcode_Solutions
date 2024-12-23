class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());

        int ans = 0;
        int n = p.size();
        int m = t.size();
        int i=0, j=0;

        while(i<n && j<m) {
            if(p[i] <= t[j]) {
                ans += 1;
                i += 1;
                j += 1;
            }
            else j += 1;

            //cout << i << " " << j << " " << ans << endl;
        }

        return ans;
    }
};