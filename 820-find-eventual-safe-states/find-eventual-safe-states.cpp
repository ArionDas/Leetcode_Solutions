class Solution {
public:

    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathvis, vector<int> &check) {
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        
        //traverse for adjacent nodes
        for(auto it:adj[node]) {
            // when the node is not visited
            if(!vis[it]) {
                if(dfsCheck(it, adj, vis, pathvis, check)==true) {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathvis[it]) {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1; // if a dfs successfully completes for a node, it's a safe node
        pathvis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& grid) {
        int V = grid.size();
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        vector<int> check(V,0);
        vector<int> safenodes;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfsCheck(i, grid, vis, pathvis, check);
            }
        }
        for(int i=0; i<V; i++)
            if(check[i]==1) safenodes.push_back(i);
            
        return safenodes;
    }
};