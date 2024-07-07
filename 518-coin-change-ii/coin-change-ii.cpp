class Solution {
public:

    int find_total_ways(int ind, vector<int>& coins, int amount, vector<vector<int>> &dp) {
        if(ind==0) {
            if(amount % coins[0]==0) return 1;
            else
                return 0;
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];

        int not_take = 0 + find_total_ways(ind-1, coins, amount, dp);
        int take = 0;
        if(coins[ind]<=amount) {
            take = find_total_ways(ind, coins, amount-coins[ind], dp);
        }

        return dp[ind][amount] = take + not_take;
    }

    int change(int amount, vector<int>& coins) {
        int len = coins.size();
        vector<vector<int>> dp(len, vector<int> (amount+1, -1));
        int ans = find_total_ways(len-1, coins, amount, dp);

        if(ans == 1e9)
            return -1;

        return ans;
    }
};