class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        vector<int> pref(n,0);

        vector<long long> prefsum(n);

        for(int i=0; i<n; i++) {
            if(i==0) prefsum[i] = nums[i];
            else prefsum[i] = prefsum[i-1]+nums[i];
        }

        for(int i=0; i<n; i++) {
            int currnum = nums[i];
            int leftsum = currnum*(i+1)-prefsum[i];
            int rightsum = (prefsum[n-1]-prefsum[i]-(n-1-i)*currnum);
            ans[i] = leftsum+rightsum;
        }
        return ans;
    }
};