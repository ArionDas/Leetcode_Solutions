class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int alice = n-1;
        int me = n-2;
        int bob = 0;
        int ans = 0;
        while(bob<me) {
            ans += piles[me];
            cout << piles[me] << " ";
            me-=2;
            alice-=2;
            bob+=1;
        }

        return ans;
    }
};