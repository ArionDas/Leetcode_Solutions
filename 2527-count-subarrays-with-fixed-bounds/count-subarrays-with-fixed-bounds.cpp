class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int out = -1, lt = -1, rt = -1;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            if(!(minK<=nums[i] && nums[i]<=maxK)) {
                out = i;
            }

            if(nums[i]==minK)
                lt = i;

            if(nums[i]==maxK)
                rt = i;

            ans += max(0, min(lt, rt)-out);
        }

        return ans;
    }
};