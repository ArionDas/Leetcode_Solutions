class Solution {
public:

    bool req_sum(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(target==0)
        return true;
    if(ind==0) {
        return arr[0] == target;
    }

    if(dp[ind][target]!=-1) {
        return dp[ind][target];
    }

    bool nt = req_sum(ind-1, target, arr, dp);
    bool t = false;
    if(arr[ind]<=target) {
        t = req_sum(ind-1, target-arr[ind], arr, dp);
    }

    return dp[ind][target] = nt || t;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    return req_sum(n-1, k, arr, dp);
}

    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
	if(sum%2!=0)
		return 0;
	else {
		int req_sum = sum/2;
		bool check = subsetSumToK(n, req_sum, arr);
		if(check) return 1;
		return 0;
	}
    }
};