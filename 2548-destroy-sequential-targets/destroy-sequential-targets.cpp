class Solution {
public:
    int destroyTargets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int maxc = 0;
        unordered_map<int,int> um;

        for(int i=n-1; i>=0; i--) {
            int rem = nums[i]%k;
            um[rem]++;
            if(um[rem]>maxc) {
                ans = nums[i];
                maxc = um[rem];
            }
            else if(um[rem] == maxc) {
                ans = min(ans, nums[i]);
                maxc = um[rem];
            }
        }

        return ans;
    }
};