class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        int n = nums.size();
        int low = 0, high = 0;
        int ans = 0;
        while(high<n) {
            int ele = nums[high];
            um[ele]++;
            while(low<high && um[ele]>k) {
                um[nums[low]]--;
                low += 1;
            }

            ans = max(ans, high-low+1);
            high += 1;
        }

        return ans;
    }
};