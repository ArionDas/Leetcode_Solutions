class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int low_ind = 0;
        int high_ind = 0;
        int n = nums.size();

        while(low_ind<n-1 && high_ind<n-1) {
            int max_ind = high_ind;
            int min_ind = low_ind;
            for (int i=low_ind; i<=high_ind; i++) {
                max_ind = max(max_ind, i+nums[i]);
                min_ind = min(min_ind, i+nums[i]);
            }
            low_ind = min_ind;
            high_ind = max_ind;
            jumps += 1;
        }
        return jumps;
    }
};