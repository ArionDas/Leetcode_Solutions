class Solution {
public:

    int find_minimum_coins(int ind, vector<int>& coins, int amount, vector<vector<int>> &dp) {
        if(ind==0) {
            if(amount % coins[0]==0) return amount / coins[0];
            else
                return 1e9;
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];

        int not_take = 0 + find_minimum_coins(ind-1, coins, amount, dp);
        int take = 1e9;
        if(coins[ind]<=amount) {
            take = 1 + find_minimum_coins(ind, coins, amount-coins[ind], dp);
        }

        return dp[ind][amount] = min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<vector<int>> dp(len, vector<int> (amount+1, -1));
        int ans = find_minimum_coins(len-1, coins, amount, dp);

        if(ans == 1e9)
            return -1;

        return ans;
    }
};