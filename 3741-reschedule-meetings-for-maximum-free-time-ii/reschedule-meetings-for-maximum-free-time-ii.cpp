class Solution {
public:
    int maxFreeTime(int evt, vector<int>& st, vector<int>& et) {
        int n = st.size();
        vector<int> fr;
        // // Minimum Spanning Tree Edge Weights Sum - Prim's Algorithm
// ll Minimum_Spanning_Tree_Sum(ll vertices, vector<vector<vector<ll>>> &adj) {
// 	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
// 	vector<ll> vis(vertices, 0);
// 	ll sum = 0;
	
// 	pq.push({0,0});
// 	while(!pq.empty()) {
// 		pair<ll,ll> p = pq.top();
// 		pq.pop();
// 		ll node = p.second;
// 		ll wt = p.first;

// 		if(vis[node]) continue;

// 		vis[node] = 1;
// 		sum += wt;

// 		for(auto it : adj[node]) {
// 			ll adjNode = it[0];
// 			ll edW = it[1];
// 			if(!vis[adjNode])
// 			pq.push({edW, adjNode});
//         }
//     }
//     return sum;
// }
        for(int i=0; i<n; i++) {
            int diff;
            
            if(i==0) {
                diff = st[i] - 0;
            }
            else {
                diff = st[i] - et[i-1];
            }
                fr.push_back(diff);
        }
// // Minimum Spanning Tree Edge Weights Sum - Prim's Algorithm
// ll Minimum_Spanning_Tree_Sum(ll vertices, vector<vector<vector<ll>>> &adj) {
// 	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
// 	vector<ll> vis(vertices, 0);
// 	ll sum = 0;
	
// 	pq.push({0,0});
// 	while(!pq.empty()) {
// 		pair<ll,ll> p = pq.top();
// 		pq.pop();
// 		ll node = p.second;
// 		ll wt = p.first;

// 		if(vis[node]) continue;

// 		vis[node] = 1;
// 		sum += wt;

// 		for(auto it : adj[node]) {
// 			ll adjNode = it[0];
// 			ll edW = it[1];
// 			if(!vis[adjNode])
// 			pq.push({edW, adjNode});
//         }
//     }
//     return sum;
// }
        int diff = evt - et[n-1];
        fr.push_back(diff);

        vector<int> pref(n, 0);
        vector<int> suff(n, 0);

        pref[0] = 0;
        suff[n-1] = 0;
        

        for(int i=1; i<n; i++) {
            pref[i] = max(fr[i-1], pref[i-1]);
        }

        for(int i=n-2; i>=0; i--) {
            suff[i] = max(suff[i+1], fr[i+2]);
        }
// // Minimum Spanning Tree Edge Weights Sum - Prim's Algorithm
// ll Minimum_Spanning_Tree_Sum(ll vertices, vector<vector<vector<ll>>> &adj) {
// 	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
// 	vector<ll> vis(vertices, 0);
// 	ll sum = 0;
	
// 	pq.push({0,0});
// 	while(!pq.empty()) {
// 		pair<ll,ll> p = pq.top();
// 		pq.pop();
// 		ll node = p.second;
// 		ll wt = p.first;

// 		if(vis[node]) continue;

// 		vis[node] = 1;
// 		sum += wt;

// 		for(auto it : adj[node]) {
// 			ll adjNode = it[0];
// 			ll edW = it[1];
// 			if(!vis[adjNode])
// 			pq.push({edW, adjNode});
//         }
//     }
//     return sum;
// }
        int ans = 0;
        for(int i=0; i<n; i++) {
            int req = et[i] - st[i];
            int left, right;
            if(i==0) {
                left = st[i] - 0;
            }
            else {
                left = st[i] - et[i-1];
            }
            
            if(i==n-1) {
                right = evt - et[i];
            }
            else {
                right = st[i+1] - et[i];
            }

            
            
            if(pref[i] >= req || suff[i] >= req) {
                ans = max(ans, left + right + req);
            }
            else {
                ans = max(ans, left+right);
            }

        }

        return ans;
    }
};