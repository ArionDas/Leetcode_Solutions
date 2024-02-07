class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> um;

        for(char c:s)
            um[c]++;

        multimap<int,char,greater<int>> mp;

        for(auto it=um.begin(); it!=um.end(); it++) {
            mp.insert({it->second,it->first});
        }

        string ans = "";
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            int temp = it->first;
            char ch = it->second;
            while(temp--) {
                ans += ch;
            }
        }

        return ans;
    }
};