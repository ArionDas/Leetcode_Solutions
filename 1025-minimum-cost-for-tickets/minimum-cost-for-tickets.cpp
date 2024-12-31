class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& c) {
        int n = days.size();
        int total_cost = 0;
        int l7=0, l30=0;

        vector<int> dp(n, 0);

        for(int r=0; r<n; r++) {
            while(days[r] - days[l7] >= 7) l7 += 1;
            while(days[r] - days[l30] >= 30) l30 += 1;

            int c1 = (r>0?dp[r-1]:0)+c[0];
            int c7 = (l7>0?dp[l7-1]:0)+c[1];
            int c30 = (l30>0?dp[l30-1]:0)+c[2];

            dp[r] = min({c1, c7, c30});
        }

        return dp[n-1];
    }
};