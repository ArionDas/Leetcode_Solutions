class Solution {
private:
    // vector<vector<int>> adj_list(vector<vector<int>> grid) {
    //     vector<vector<int>> adj(grid.size());

    //     for(int i=0; i<grid.size(); i++) {
    //         for(int j=0; j<grid[i].size(); j++) {
    //             if(grid[i][j]!=0) {
    //                 adj[i].push_back(j);
    //                 adj[j].push_back(i);
    //             }
    //         }
    //     }
    //     return adj;
    // }

    bool check(int start, int V, vector<vector<int>> &adj, int color[]) {
        queue<int> q;
        q.push(start);

        color[start] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it:adj[node]) {
                if(color[it]==-1) {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                    return 0;
            }
        }
        return 1;
    }

public:
    bool isBipartite(vector<vector<int>>& grid) {
        int V = grid.size();
        //vector<vector<int>> adj = adj_list(grid);

        int color[V];
        for(int i=0; i<V; i++) color[i] = -1;

        for(int i=0; i<V; i++) {
            if(color[i]==-1) {
                if(check(i,V,grid,color)==false)
                    return 0;
            }
        }
        return 1;
    }
};