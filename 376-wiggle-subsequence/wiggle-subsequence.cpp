class Solution {
public:

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> up(n+1, 0), down(n+1, 0);

        up[0] = 1;
        down[0] = 1;

        for(int i=1; i<n; i++) {
            if(nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            }
            else if(nums[i] < nums[i-1]) {
                up[i] = up[i-1];
                down[i] = up[i-1] + 1;
            }
            else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }

        return max(down[n-1], up[n-1]);
    }
};