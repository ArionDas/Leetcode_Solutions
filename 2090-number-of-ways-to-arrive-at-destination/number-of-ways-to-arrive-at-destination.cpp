#define ll long long
class Solution {
public:
    const ll mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        ll src = 0;
        vector<vector<vector<ll>>> nodes(n);
        for(auto it:roads) {
            ll u = it[0];
            ll v = it[1];
            ll wt = it[2];
            nodes[u].push_back({v, wt});
            nodes[v].push_back({u, wt});
            //nodes[v].push_back({u, wt});
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        q.push({0, src});
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n);
        ways[src] = 1;
        dist[src] = 0;
        while(!q.empty()) {
            ll node = q.top().second;
            ll time = q.top().first;
            q.pop();

            if(time > dist[node]) {
                continue;
            }

            for(auto it:nodes[node]) {
                ll adjNode = it[0];
                ll edgtime = it[1];
                if(dist[adjNode] > (long long) time + (long long) edgtime) {
                    dist[adjNode] = (long long) time + (long long) edgtime;
                    ways[adjNode] = ways[node];
                    q.push({dist[adjNode], adjNode});
                }              
                else if(dist[adjNode] == (long long) time + (long long) edgtime){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};