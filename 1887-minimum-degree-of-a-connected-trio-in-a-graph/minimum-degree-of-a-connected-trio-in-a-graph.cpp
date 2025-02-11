class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> degree(n+1, 0);
        //int n = edges.size();
        vector<vector<int>> adj(n+1);
        //unordered_set<pair<int, int>> um;
        vector<vector<int>> grid(n+1, vector<int>(n+1, 0));

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            degree[u] += 1;
            degree[v] += 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
            grid[u][v] = grid[v][u] = 1;
        }

        int ans = INT_MAX;

        for(int i=1; i<=n; i++) {
            vector<int> temp = adj[i];
            int sz = temp.size();

            for(int j=0; j<sz; j++) {
                for(int k=j+1; k<sz; k++) {
                    int u = temp[j];
                    int v = temp[k];
                    int deg = 0;

                    if(grid[u][v]) {
                        deg = degree[i] + degree[u] + degree[v] - 6;
                        ans = min(ans, deg);
                    }

                }
            }
        }

        if(ans == INT_MAX)
            return -1;
        return ans;

    }
};