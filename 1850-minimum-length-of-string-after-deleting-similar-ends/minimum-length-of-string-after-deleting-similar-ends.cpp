class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;

        int ans = n;

        while(i<j) {
            char ch;
            if(s[i]==s[j]) {
                ch = s[i];
                while(s[i]==ch && i<=j) {
                    i += 1;
                    ans -= 1;
                }
                while(s[j]==ch && i<=j) {
                    j -= 1;
                    ans -= 1;
                }
                cout << i << " " << j << endl;
            }
            else {
                break;
            }
        }

        return ans;
    }
};