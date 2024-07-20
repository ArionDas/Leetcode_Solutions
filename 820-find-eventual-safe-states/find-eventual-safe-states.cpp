class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> safe_nodes;

        vector<int> indg(V, 0);
        vector<vector<int>> reverse_edges(V);
        for(int i=0; i<V; i++) {
            for(auto it:adj[i]) {
                indg[i]++;
                reverse_edges[it].push_back(i);
            }
        }

        queue<int> q;
        for(int i=0; i<V; i++) {
            if(indg[i]==0)
                q.push(i);
        }

        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it:reverse_edges[node]) {
                indg[it]--;
                if(indg[it]==0)
                    q.push(it);
            }
        }

        sort(topo.begin(), topo.end());
        return topo;
    }
};