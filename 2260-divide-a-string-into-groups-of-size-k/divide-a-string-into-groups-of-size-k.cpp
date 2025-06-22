class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int rem = 0;
        if(s.length()%k!=0)
            rem = k - s.length()%k;
            
        while(rem--) {
            s += fill;
        }

        cout << s << endl;

        int n = s.length();
        int j=0;
        string word = "";

        while(j<n) {
            if(j%k==0 && j!=0) {
                ans.push_back(word);
                word = s[j];
            }
            else {
                word += s[j];
                // j += 1;
            }
            j += 1;
        }

        ans.push_back(word);

        return ans;
    }
};