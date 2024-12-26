class Solution {
public:

    int find_target_sum(int ind, int n, int sum, vector<int> &nums, int target, vector<vector<int>> &dp) {
        if(ind == n) {
            if(sum == target) {
                return dp[ind][sum+1000] = 1;
            }
            return 0;
        }

        if(dp[ind][sum+1000] != -1) {
            return dp[ind][sum+1000];
        }

        return dp[ind][sum+1000] = find_target_sum(ind+1, n, sum+nums[ind], nums, target, dp) + find_target_sum(ind+1, n, sum-nums[ind], nums, target, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2002, -1));

        int ans = find_target_sum(0, n, 0, nums, target, dp);

        return ans;
    }
};