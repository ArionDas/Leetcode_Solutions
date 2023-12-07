class Solution {
public:
    string largestOddNumber(string num) {
        int p = num.length()-1;

        string ans = "";

        for(; p>=0; p--) {
            if((num[p]-'0')%2!=0) {
                ans = num.substr(0,p+1);
                break;
            }
        }
        return ans;
    }
};