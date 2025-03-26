class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> val;
        for(auto i:grid) {
            for(auto j:i) {
                val.push_back(j);
            }
        }

        bool parity = 1;
        int n = val.size();

        // for(int i=1; i<n; i++) {
        //     if(val[i]%2==0 && val[i-1]%2!=0 || val[i]%2!=0 && val[i-1]%2==0) {
        //         return -1;
        //     }
        // }

        sort(val.begin(), val.end());
        int req = val[n/2];

        int ans = 0;
        for(auto it:val) {
            int times = abs(it-req)/x;
            if(times * x != abs(it-req))
                return -1;
            ans += abs(it-req)/x;
        }

        return ans;
    }
};