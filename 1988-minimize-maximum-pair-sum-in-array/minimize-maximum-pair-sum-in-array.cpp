class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int minmax = INT_MIN;
        int left=0, right=n-1;

        while(left<right) {
            minmax = max(minmax, nums[left++]+nums[right--]);
        }

        return minmax;
    }
};