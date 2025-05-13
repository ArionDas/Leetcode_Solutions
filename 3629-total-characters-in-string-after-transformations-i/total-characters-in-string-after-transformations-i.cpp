class Solution {
public:
    #define ll long long
    const ll mod = 1e9+7;

    ll mod_add(ll a, ll b) {
        a = a%mod;
        b = b%mod;

        return (((a+b)%mod) + mod) % mod;
    }

    int lengthAfterTransformations(string s, int t) {
        ll nums[26] = {0};
        for(char ch:s) nums[ch-'a'] += 1;

        while(t--) {
            ll curr[26] = {0};
            for(int j=0; j<26; j++) {
                if(j==25 && nums[j]>0) {
                    curr[0] = mod_add(curr[0], nums[j]);
                    curr[1] = mod_add(curr[1], nums[j]);
                }
                else {
                    if(j<25) curr[j+1] = mod_add(curr[j+1], nums[j]);
                }
            }
            for(int j=0; j<26; j++)
                nums[j] = curr[j];
        }

        ll cnt = 0;
        for(int i:nums) cnt = mod_add(cnt, i);

        return (int)cnt;
    }
};