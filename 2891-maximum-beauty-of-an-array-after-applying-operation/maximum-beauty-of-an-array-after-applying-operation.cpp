class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int i=0, j=0;
        int n = nums.size();
        int len = 0;

        while(j<n) {
            if(nums[j]-nums[i] <= 2*k) {
                j += 1;
                len += 1;
                ans = max(ans, len);
            }
            else {
                while(nums[j]-nums[i] > 2*k) {
                    i += 1;
                }
                ans = max(ans, len);
                len = (j-i);
            }
        }

        return ans;
    }
};