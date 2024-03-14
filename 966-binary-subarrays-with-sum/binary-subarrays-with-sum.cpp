class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> um;
        um[0]++;
        int sum = 0;
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];

            int req = sum - goal;
            if(um.find(req)!=um.end())
                ans += um[req];

            um[sum]++;
        }

        return ans;
    }
};