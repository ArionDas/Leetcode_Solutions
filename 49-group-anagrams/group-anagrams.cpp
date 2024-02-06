class Solution {
public:

    string getsig(string s) {
        vector<int> count(26,0);
        for(char c:s)
            count[c-'a']++;

        stringstream ss;

        for(int i=0; i<26; i++) {
            if(count[i]!=0)
                ss << (char)('a'+i) << count[i];
        }
        return ss.str();
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> um;

        for(string s:strs)
            um[getsig(s)].push_back(s);

        for(auto entry:um)
            result.push_back(entry.second);

        return result;
    }
};