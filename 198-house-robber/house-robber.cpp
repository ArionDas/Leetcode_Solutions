class Solution {
public:
    int rob(vector<int>& nums) {
        int curr = nums[0];
        int prev = nums[0];
        int prev_2 = 0;

        for(int i=1; i<nums.size(); i++) {
            int take = nums[i] + prev_2;
            int not_take = 0 + prev;

            curr = max(take, not_take);
            prev_2 = prev;
            prev = curr;
        }

        return prev;
    }
};