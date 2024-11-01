class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int k = 0;
        int n = s.length();

        for(int i=0; i<n; i++) {
            if(ans.length() < 2) {
                ans += s[i];
                k += 1;
            }
            else {
                int l = k-1;
                if(ans[l] == ans[l-1] && ans[l] == s[i])
                    continue;
                else {
                    ans += s[i];
                    k += 1;
                }
            }
            //cout << i << " " << k << " " << ans << endl;
        }

        return ans;
    }
};