class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n = g.size();
        int m = s.size();
        int i=m-1,j=n-1;
        int ans = 0;

        while(i>=0 && j>=0) {
            if(s[i]>=g[j]) {
                ans += 1;
                j -= 1;
                i -= 1;
            }
            else {
                j -= 1;
            }
            cout << j << " ";
        }
        return ans;
    }
};