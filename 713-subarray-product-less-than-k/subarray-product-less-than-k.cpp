class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int low=0,high=0;
        if(k<2)
            return 0;
        int n = nums.size();
        int prod = 1;
        int ans = 0;
        while(high<n) {
            prod *= nums[high];

            // if(prod<k)
            //     ans += 1;
            // if(nums[high]<k)
            //     ans += 1;

            while(prod>=k) {
                prod /= nums[low];
                low += 1;
                // low += 1;
                // if(prod<k)
                //     ans += 1;
            }
            ans += (1+high-low);
            high += 1;
        }

        return ans;
    }
};