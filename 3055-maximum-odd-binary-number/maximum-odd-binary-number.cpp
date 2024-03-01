class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        for(char c:s)
            if(c=='1')
                ones += 1;
        
        string ans = "";
        int zeros = s.length()-ones;
        
        while(ones>1) {
            ans += '1';
            ones--;
        }
        while(zeros) {
            ans += '0';
            zeros--;
        }
        ans += '1';
        
        return ans;
    }
};