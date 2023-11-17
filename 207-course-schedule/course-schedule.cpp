class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& pq) {

        vector<int> adj[nc];
        for(int i=0; i<pq.size(); i++) {
            adj[pq[i][0]].push_back(pq[i][1]);
        }

        vector<int> indegree(nc,0);
        for(int i=0; i<pq.size(); i++) {
            indegree[pq[i][1]]++;
        }

        queue<int> q;
        int cnt = 0;
        for(int i=0; i<nc; i++) {
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt += 1;
            for(auto it:adj[node]) {
                indegree[it]--;
                if(indegree[it]==0) {
                    q.push(it);
                }
            }
        }

        if(cnt==nc) return 1;
        return 0;
    }
};