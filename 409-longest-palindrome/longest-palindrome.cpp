class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> um;
        int len = s.length();

        for(char ch:s)
            um[ch] += 1;

        int ans = 0;
        bool odd = 0;

        for(auto it=um.begin(); it!=um.end(); it++) {
            if(it->second % 2==0) {
                ans += it->second;
            }
            else {
                ans += (it->second - 1);
                odd = 1;
            }
        }

        if(odd)
            ans += 1;

        return ans;
    }
};