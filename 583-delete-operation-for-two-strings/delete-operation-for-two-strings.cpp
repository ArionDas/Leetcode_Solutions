class Solution {
public:

    int lcs(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<int> prev(m+1,0); 
        vector<int> curr(m+1,0);

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1]==t[j-1]) {
                    curr[j] = 1 + prev[j-1];
                }
                else {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }

        return curr[m];
    }

    int minDistance(string word1, string word2) {
        return (word1.size() + word2.size() - 2*lcs(word1, word2));
    }
};