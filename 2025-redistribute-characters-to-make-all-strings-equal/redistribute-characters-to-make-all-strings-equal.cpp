class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> um;
        int len = words.size();
        for(int i=0; i<len; i++) {
            string temp = words[i];

            for(int j=0; j<temp.length(); j++) {
                um[temp[j]]++;
            }
        }

        for(auto it=um.begin(); it!=um.end(); it++) {
            if(it->second%len != 0)
                return 0;
        }
        return 1;
    }
};