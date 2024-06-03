class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        int i=0, j=0;

        while(i<s_len && j<t_len) {
            if(s[i]==t[j]) {
                j += 1;
            }
            i += 1;
        }

        return (t_len-j);
    }
};