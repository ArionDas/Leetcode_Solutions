class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        int sum = 0;

        for(int i=0; i<n; i++) {
            if(i==0) {
                sum += nums[i];
                continue;
            }

            if(nums[i] > nums[i-1]) {
                sum += nums[i];
            }
            else {
                ans = max(ans, sum);
                sum = nums[i];
            }
        }

        ans = max(ans, sum);

        return ans;
    }
};