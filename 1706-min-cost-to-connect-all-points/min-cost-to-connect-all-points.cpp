class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<vector<int>>> adj(points.size());
        int n = points.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i!=j) {
                    int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    adj[i].push_back({j, dist});
                }
            }
        }
        int V = n;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(V, 0);
        
        pq.push({0,0});
        int sum = 0;
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int wt = it.first;
            
            if(vis[node] == 1)
                continue;
                
            vis[node] = 1;
            sum += wt;
            
            for(auto it : adj[node]) {
                int adjNode = it[0];
                int edW = it[1];
                if(!vis[adjNode])
                    pq.push({edW, adjNode});
            }
        }
        
        return sum;
    }
};