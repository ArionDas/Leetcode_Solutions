class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> um;

        int ans = 0;

        for(int i=0; i<words.size(); i++) {
            um.clear();
            for(char ch:chars) {
                um[ch]++;
            }

            bool flag = 1;

            for(int j=0; j<words[i].length(); j++) {
                if(um.find(words[i][j])==um.end()) {
                    flag = 0;
                    break;
                }
                else {
                    um[words[i][j]]--;
                    if(um[words[i][j]]==0)
                        um.erase(words[i][j]);
                }
            }
            if(flag) {
                ans += words[i].length();
            }
        }
        return ans;
    }
};