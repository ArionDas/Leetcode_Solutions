class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ones=0, zero = 0;
        int ans = 0;
        int i=0, j=0;
        unordered_map<int,int> um;
        int sum = 0;
        for(; i<nums.size(); i++) {
            sum += nums[i]==1? 1:-1;

            if(sum==0) {
                ans = i+1;
            }
            else if(um.find(sum)!=um.end())
                ans = max(ans, i-um[sum]);
            else
                um[sum] = i;
        }
        return ans;
    }
};