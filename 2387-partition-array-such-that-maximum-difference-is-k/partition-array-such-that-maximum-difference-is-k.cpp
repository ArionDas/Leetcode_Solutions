class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int cnt = 0;
        int i=0, j=0;
        int n = nums.size();

        while(j<n) {
            if(nums[j] - nums[i] > k) {
                cnt += 1;
                i = j;
            }
            j += 1;
        }

        if(i != n)
            cnt += 1;

        return cnt;
    }
};