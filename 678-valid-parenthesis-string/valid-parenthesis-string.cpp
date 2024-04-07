class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;

        //int right_parenthesis = 0, left_parenthesis = 0;
        int len = s.length();
        int low=0,high=0;

        for(int i=0; i<len; i++) {
            if(s[i]=='(') {
                low += 1;
                high += 1;
            }
            else if(s[i]==')') {
                low = max(0, --low);
                high -= 1;
            }
            else {
                low = max(0, --low);
                high += 1;
            }
            if(high<0)
                return 0;
        }
        return low == 0;
    }
};