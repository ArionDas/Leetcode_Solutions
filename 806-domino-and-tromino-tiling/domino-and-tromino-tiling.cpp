class Solution {
public:

    const int mod = 1e9+7;

    int numTilings(int n) {

        if(n<3)
            return n;

        vector<long long> d(n+1, 0);
        vector<long long> t(n+1, 0);

        d[0] = 0, d[1] = 1, d[2] = 2;
        t[0] = 0, t[1] = 1, t[2] = 2;

        for(int i=3; i<=n; i++) {
            d[i] = (d[i-1]%mod + d[i-2]%mod + (2 * t[i-2])%mod) % mod;
            t[i] = (t[i-1]%mod + d[i-1]%mod) % mod;
        }

        return d[n];
    }
};