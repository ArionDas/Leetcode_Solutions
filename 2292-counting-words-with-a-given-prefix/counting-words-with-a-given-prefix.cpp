class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int ans = 0;
        int m = pref.length();

        for(int i=0; i<n; i++) {
            if(words[i].substr(0, m) == pref)
                ans += 1;
        }

        return ans;
    }
};