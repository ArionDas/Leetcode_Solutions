class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,int> m;
        int j=0;
        int max_len=-1;
        while(j<s.length()) {
            if(m.find(s[j])!=m.end()) {
                max_len = max(max_len,j-m[s[j]]-1);
                m[s[j]] = min(j,m[s[j]]);
            }
            else
                m[s[j]] = j;
            j++;
        }
        return max_len;
    }
};