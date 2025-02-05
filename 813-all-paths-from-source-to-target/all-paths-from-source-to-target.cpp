class Solution {
public:

    void find_paths(int node, vector<int> path, vector<vector<int>>& paths, vector<vector<int>>& graph, vector<bool>& vis, int V) {
        if(node == V-1) {
            path.push_back(node);
            paths.push_back(path);
            return;
        }

        //vis[node] = 1;

        path.push_back(node);
        for(auto it:graph[node]) {
            find_paths(it, path, paths, graph, vis, V);
        }
        path.pop_back();

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;

        int V = graph.size();
        vector<bool> vis(V, 0);

        find_paths(0, {}, paths, graph, vis, V);

        return paths;
    }
};