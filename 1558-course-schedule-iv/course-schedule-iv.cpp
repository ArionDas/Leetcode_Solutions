class Solution {
public:
    vector<bool> checkIfPrerequisite(int nc, vector<vector<int>>& prq, vector<vector<int>>& qr) {

        int n = nc;
        vector<vector<bool>> pos(n+1, vector<bool>(n+1, 0));

        vector<vector<int>> adj(n);
        for(int i=0; i<prq.size(); i++) {
            adj[prq[i][0]].push_back(prq[i][1]);
        }

        for(int i=0; i<nc; i++) {
            int src = i;
            vector<bool> vis(nc+1, 0);
            vis[src] = 1;
            queue<int> q;
            q.push(src);
            
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                vis[node] = 1;
                for(auto it:adj[node]) {
                    pos[src][it] = 1;
                    if(!vis[it])
                        q.push(it);
                }

            }
        }

            vector<bool> ans;
            for(auto it:qr) {
                int u = it[0];
                int v = it[1];

                ans.push_back(pos[u][v]);
            }

            return ans;
    }
};