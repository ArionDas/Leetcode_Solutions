class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int maxfreq = 0;
        long currsum = 0;

        sort(nums.begin(), nums.end());
        int left = 0, right = 0;
        for(; right<nums.size(); right++) {
            currsum += nums[right];

            while(currsum + k < static_cast<long>(nums[right])*(right-left+1)) {
                currsum -= nums[left];
                left++;
            }

            maxfreq = max(maxfreq, right-left+1);
        }
        return maxfreq;
    }
};