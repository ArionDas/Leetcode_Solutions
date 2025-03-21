class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& in, vector<string>& s) {
        unordered_map<string, vector<string>> g;
        unordered_map<string, int> ind;
        for(int i=0; i<r.size(); i++) {
            ind[r[i]] = in[i].size();
            for(auto x: in[i]) g[x].push_back(r[i]);
        }

        vector<string> result;
        queue<string> q;

        for(auto x:s) {
            for(auto y:g[x]) {
                ind[y] -= 1;
                if(ind[y]==0) {
                    result.push_back(y);
                    q.push(y);
                }
            }
        }

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            for(auto x:g[curr]) {
                ind[x] -= 1;
                if(ind[x]==0) {
                    result.push_back(x);
                    q.push(x);
                }
            }
        }

        return result;
    }
};