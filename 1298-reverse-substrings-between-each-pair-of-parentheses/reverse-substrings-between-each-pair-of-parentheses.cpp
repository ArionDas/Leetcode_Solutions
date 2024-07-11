class Solution {
public:
    string reverseParentheses(string s) {
        string temp, rev_;

        for(char ch:s) {
            if (ch != ')')
                temp.push_back(ch);
            else {
                rev_ = "";
                char r = temp.back();
                
                for(; r!='('; r=temp.back()) {
                    rev_ += r;
                    temp.pop_back();
                }

                temp.pop_back();

                temp += rev_;
            }
        }
        return temp;
    }
};