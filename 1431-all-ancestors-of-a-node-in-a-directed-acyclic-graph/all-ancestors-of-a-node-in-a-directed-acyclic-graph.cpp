class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        // Initialize the adjacency list
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[1]].push_back(it[0]);
        }

        // Resultant vector to store the ancestors for each node
        vector<vector<int>> ans;

        // Find ancestors for each node
        for (int i = 0; i < n; i++) {
            queue<int> q;
            q.push(i);
            vector<int> v;
            vector<int> vis(n, 0);

            // Perform BFS to find all ancestors of node i
            while (!q.empty()) {
                for (auto it : adj[q.front()]) {
                    if (!vis[it]) {
                        q.push(it);
                        v.push_back(it);
                        vis[it] = 1;
                    }
                }
                q.pop();
            }

            // Sort the list of ancestors
            sort(v.begin(), v.end());

            // Add to the result
            ans.push_back(v);
        }

        return ans;
    }
};