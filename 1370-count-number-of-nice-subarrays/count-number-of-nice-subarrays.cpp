class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        int m = n+1;
        vector<int> prefix(m,0);
        int odd = 0;

        for(int i=0; i<n; i++) {
            prefix[odd]++;

            if(nums[i]&1)
                odd += 1;

            if(odd >= k) {
                count += prefix[odd-k];
            }
        }
        return count;
    }
};