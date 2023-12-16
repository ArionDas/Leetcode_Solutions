class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> um1;
        // unordered_map<char,int> um2;

        for(int i=0; i<s.length(); i++) um1[s[i]]++;
        for(int i=0; i<t.length(); i++) {
            if(um1.find(t[i])==um1.end()) return false;
            um1[t[i]]--;
        }

        for(auto i=um1.begin(); i!=um1.end(); i++) {
            if(i->second!=0) return 0;
        }
        return 1;
    }
};