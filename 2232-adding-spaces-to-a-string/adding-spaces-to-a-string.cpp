class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n = s.length();
        int k = 0;
        for(int i=0; i<n; i++) {
            if(k < spaces.size() && spaces[k]==i) {
                ans += ' ';
                k += 1;
                i -= 1;
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};