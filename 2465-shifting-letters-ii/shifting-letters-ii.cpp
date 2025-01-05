class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> shift(n+1, 0);
        vector<int> diff(n+1, 0);

        for(int i=0; i<shifts.size(); i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int change = shifts[i][2];

            if(change==1) {
                shift[start] += 1;
                shift[end+1] -= 1;
            }
            else {
                shift[start] -= 1;
                shift[end+1] += 1;
            }
        }

        int total = 0;
        for(int i=0; i<n; i++) {
            total += shift[i];
            diff[i] = total;
        }

        for(int i=0; i<n; i++) {
            char ch = s[i];
            int change = diff[i];
            change %= 26;
            if(change<0) {
                change = abs(change);
                while(change--) {
                    if(ch=='a') ch = 'z';
                    else ch = ch-1;
                }
            }
            else {
                while(change--) {
                    if(ch=='z') ch = 'a';
                    else ch = ch+1;
                }
            }
            s[i] = ch;
        }

        return s;
    }
};