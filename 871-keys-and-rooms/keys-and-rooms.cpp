class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //unordered_map<int, int> um;
        int V = rooms.size();

        vector<bool> vis(V, 0);
        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            for(auto key:rooms[node]) {
                //um[key] += 1;
                if(!vis[key])
                    q.push(key);
            }
        }

        bool f = 1;
        for(auto it:vis) {
            if(!it) {
                return 0;
            }
        }

        return 1;
    }
};