class Solution {
public:

    // vector<vector<int>> make_adjacent_list(int n, vector<vector<int>>& edges) {

    //     vector<vector<int>> adj(n);

    //     for(int i=0; i<n; i++) {
    //         int a = edges[i][0];
    //         int b = edges[i][1];

    //         adj[a].push_back(b);
    //         adj[b].push_back(a);
    //     }

    //     return adj;
    // }

    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int edges = 0;

        for(auto child:adj[node]) {
            if(child==parent) continue;
            edges += dfs(child, node, adj, hasApple);
        }

        if(node==0) return edges;
        if(edges>0 || hasApple[node])
            return edges + 1;

        return edges;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>> adj(n);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        return 2*dfs(0, -1, adj, hasApple);
    }
};