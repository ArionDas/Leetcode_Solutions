class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int len = matches.size();
        vector<int> ans_zero;
        vector<int> ans_one;
        sort(matches.begin(), matches.end());
        unordered_map<int,int> um;

        for(int i=0; i<len; i++) {
            um[matches[i][1]]++;
            if(um.find(matches[i][0])==um.end()) {
                um[matches[i][0]] = 0;
            }
        }

        for(auto it=um.begin(); it!=um.end(); it++) {
            if(it->second==0) {
                ans_zero.push_back(it->first);
            }
            else if(it->second==1) {
                ans_one.push_back(it->first);
            }
        }

        sort(ans_zero.begin(), ans_zero.end());
        sort(ans_one.begin(), ans_one.end());
        return {ans_zero, ans_one};
    }
};