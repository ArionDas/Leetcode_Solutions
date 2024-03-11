class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> um,um2;
        for(char ch:s) {
            um2[ch]++;
        }
        string ans = "";
        for(char ch:order) {
            int k = um2[ch];
            while(k--) {
                ans += ch;
                um[ch]++;
            }          
        }

        for(char ch:s) {
            if(um.find(ch)==um.end())
                ans += ch;
        }
        return ans;
    }
};