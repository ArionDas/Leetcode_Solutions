class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        int left = 0, right = 1;
        int mask = nums[0];

        while(right < n) {
            while((mask & nums[right]) != 0)
                mask ^= nums[left++];
            mask |= nums[right];
            maxi = max(maxi, right-left+1);
            right += 1;
        }
        return maxi;
    }
};