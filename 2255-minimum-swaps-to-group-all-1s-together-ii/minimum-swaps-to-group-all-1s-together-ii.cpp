class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        if(ones == 0)
            return 0;

        vector<int> extended_nums(nums.begin(), nums.end());
        extended_nums.insert(extended_nums.end(), nums.begin(), nums.end());

        int curr_zeros = count(extended_nums.begin(), extended_nums.begin() + ones, 0);
        int min_zeros = curr_zeros;

        for (int i = ones; i < extended_nums.size(); ++i) {
            if (extended_nums[i] == 0) curr_zeros++;
            if (extended_nums[i - ones] == 0) curr_zeros--;

            min_zeros = min(min_zeros, curr_zeros);
        }

        return min_zeros;
    }
};