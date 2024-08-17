class Solution {
public:

    int find_min_cost(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];

        int mini = INT_MAX;

        for(int ind = i; ind<=j; ind++) {
            int cost = cuts[j+1] - cuts[i-1] + 
                        find_min_cost(i, ind-1, cuts, dp) +
                        find_min_cost(ind+1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        // its imp to have the cuts array sorted, so that subproblems are independent of each other
        // length of the stick = cuts[j+1] - cuts[i-1]
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c+1, vector<int> (c+1, -1));

        return find_min_cost(1, c, cuts, dp);
    }
};