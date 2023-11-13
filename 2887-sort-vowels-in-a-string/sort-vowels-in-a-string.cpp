class Solution {
public:
    string sortVowels(string s) {
        string t = "";
        vector<char> chars;

        int n = s.length();
        for(int i=0; i<n; i++) {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U') {
                chars.push_back(s[i]);
                s[i] = '.';
            }
        }

        sort(chars.begin(), chars.end());
        int k = 0;
        for(int i=0; i<n; i++) {
            if(s[i]=='.') {
                s[i] = chars[k++];
            }
        }

        return s;
    }
};