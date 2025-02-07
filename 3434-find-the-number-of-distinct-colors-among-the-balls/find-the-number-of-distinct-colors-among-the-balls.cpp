class Solution {
public:
    vector<int> queryResults(int lmt, vector<vector<int>>& q) {
        unordered_map<int, int> um, um2;
        int n = q.size();
        vector<int> ans;

        for(int i=0; i<n; i++) {
            int x = q[i][0];
            int y = q[i][1];

            //um2[x] = y;

            if(um2.find(x) != um2.end()) {
                int prev = um2[x];
                um[prev] -= 1;
                if(um[prev] == 0) {
                    um.erase(prev);
                }
                //um2[x] = y;
            }
            um2[x] = y;
            um[y] += 1;

            ans.push_back(um.size());
        }

        return ans;

    }
};