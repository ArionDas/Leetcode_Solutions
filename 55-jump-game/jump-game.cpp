class Solution {
public:

    bool canJump(vector<int> &nums) {
        // for every index, we calculate the maximum index that can be reached from there.
        // If we reach an index with value zero, and our max_ind is not greater than the index
        // then, we won't be able to pass it, hence return false.
        int max_ind = nums[0];
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(max_ind >= n-1) return 1;

            if(nums[i]==0 && max_ind==i) return false;

            if(i + nums[i] > max_ind) max_ind = i + nums[i];
        }

        return 1;
    }
};