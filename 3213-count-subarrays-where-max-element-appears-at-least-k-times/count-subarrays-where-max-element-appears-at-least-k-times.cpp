class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        //long long count = 0;
        int maxi = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        unordered_map<int,int> um;
        int low=0,high=0;
        while(high<n) {
            um[nums[high]]++;

            while(um.find(maxi)!=um.end() && um[maxi]>=k) {
                um[nums[low]]--;
                low += 1;
                ans += n-high;
            }
            high += 1;
        }
        // while(low<n) {
        //     if(um.find(maxi)!=um.end() && um[maxi]>=k) {
        //         ans += 1;
        //         um[nums[low]]--;
        //         //low += 1;
        //     }
        //     low += 1;
        // }
        return ans;
    }
};