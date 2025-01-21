class Solution {
public:

    static bool comp(const pair<int, string>& a, const pair<int, string>& b) {
        return (a.first < b.first) || (a.first == b.first && a.second < b.second);
    }

    vector<string> watchedVideosByFriends(vector<vector<string>>& wv, vector<vector<int>>& f, int id, int level) {
        int V = wv.size();

        if(level == 0) {
            return wv[id];
        }

        vector<bool> vis(V, 0);
        int src = id;
        queue<int> q;
        int l = 0;
        q.push(src);
        vis[src] = 1;
        while(!q.empty()) {
            int qs = q.size();
            while(qs--) {
                int node = q.front();
                q.pop();
                //vis[node] = 1;
                for(auto adjNode : f[node]) {
                    if(!vis[adjNode]) {
                        vis[adjNode] = 1;
                        q.push(adjNode);
                    }
                }
            }
            l += 1;
            if(l == level) {
                break;
            }
        }

        unordered_map<string, int> um;

        int qs = q.size();
        while(qs--) {
            int node = q.front();
            q.pop();

            for(auto vid:wv[node]) {
                um[vid]++;
            }

        }

        vector<pair<int, string>> vp;
        for(auto it:um) {
            vp.push_back({it.second, it.first});
        }

        sort(vp.begin(), vp.end(), comp);

        vector<string> ans;
        for(auto it:vp) {
            ans.push_back(it.second);
        }

        return ans;

    }
};