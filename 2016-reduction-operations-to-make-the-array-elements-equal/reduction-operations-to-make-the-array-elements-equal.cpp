class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n==1) return 0;
        int count = 0;

        for(int i=0; i<n; i++) {
            while(nums[i]==nums[i+1]) {
                i += 1;
            }
            count += (n-i-1);
        }

        return count;
    }
};