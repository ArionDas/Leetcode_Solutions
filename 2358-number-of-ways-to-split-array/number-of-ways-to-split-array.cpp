class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), (long long)0);
        long long curr_sum = 0;
        long long ans = 0;
        for(int i=0; i<n-1; i++) {
            curr_sum += nums[i];
            if(curr_sum >= (sum-curr_sum)) {
                ans += 1;
            }
        }
        return ans;
    }
};