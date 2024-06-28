class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> um;
        //multiset<int> ms;
        int len = roads.size();
        vector<int> deg(n);
        // for(int i=0; i<len; i++) {
        //     int a = roads[i][0];
        //     int b = roads[i][1];
        //     um[a] += 1;
        //     um[b] += 1;
        // }
        for(auto& e : roads) {
            deg[e[0]]++;
            deg[e[1]]++;
        }
        // priority_queue<int, vector<int>, greater<int>> pq;

        // for(auto it=um.begin(); it!=um.end(); it++) {
        //     pq.push(it->second);
        // }
        sort(deg.begin(), deg.end());
        long long ans = 0;
        // long long ans = 0;
        // long long k = 1;

        // while(!pq.empty()) {
        //     int num = pq.top();
        //     pq.pop();

        //     ans += k*num;
        //     //cout << k << " " << num << endl;
        //     k += 1;
        // }
        for(int i = 0; i < n; i++) {
            ans += (i + 1ll) * deg[i];
        }
        return ans;
    }
};