class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.length();
        int a = len/2; 
        int b = len/2;

        //unordered_map<char,int> um1, um2;
        int c1 = 0;
        int c2 = 0;

        for(int i=0; i<a; i++) {
            //cout << s[i] << " ";
            if(s[i]=='a'||s[i]=='A'||s[i]=='o'||s[i]=='O'||s[i]=='i'||s[i]=='I'||s[i]=='e'||s[i]=='E'||s[i]=='u'||s[i]=='U') {
                //um1[s[i]]++;
                c1 += 1;
                cout << s[i] << " ";
            }
        }
        cout << endl;
        for(int i=a; i<len; i++) {
            //cout << s[i] << " ";
            if(s[i]=='a'||s[i]=='A'||s[i]=='o'||s[i]=='O'||s[i]=='i'||s[i]=='I'||s[i]=='e'||s[i]=='E'||s[i]=='u'||s[i]=='U') {
                //um2[s[i]]++;
                c2 += 1;
                cout << s[i] << " ";
            }
        }

        if(c1 == c2)
            return 1;
        else
            return 0;
    }
};