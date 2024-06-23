class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int len = nums.size();

        int ans = 1;
        int curr = 1;

        int i=0, j=1;
        map<int,int> mp;
        mp[nums[0]] += 1;
        while(j<len) {
            mp[nums[j]] += 1;

            while(mp.rbegin()->first - mp.begin()->first > limit) {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i += 1;
            }

            ans = max(ans, j-i+1);
            j += 1;
        }

        return ans;
    }
};