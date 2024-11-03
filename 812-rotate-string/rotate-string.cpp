class Solution {
public:

    string rotate(string &str) {
        str = str.substr(1,str.length()-1) + str[0];
        return str;
    }

    bool rotateString(string s, string goal) {
        for(int i=0; i<s.length(); i++) {
            if(rotate(s)==goal) return 1;
        }
        return 0;
    }
};