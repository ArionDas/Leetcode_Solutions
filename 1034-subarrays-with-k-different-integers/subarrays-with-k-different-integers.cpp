class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size()-1;
        unordered_map<int, int> mp;
        int ans = 0;
        while(r<=n){
            mp[nums[r]]++;
            while(mp.size()>k && l<=r){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            ans += (r - l);
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int f = solve(nums, k) - solve(nums, k - 1);
        return f;
    }
};