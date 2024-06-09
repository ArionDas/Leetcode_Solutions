class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> v(k+1, 0);
        long int sum = 0;

        for(int i=0; i<n; i++) {
            sum += nums[i];
            int rem = sum%k;
            if(rem<0) rem += k;
            v[rem] += 1;
        }

        int ans = v[0];

        for(int i=0; i<k; i++) {
            int num = (v[i]*(v[i]-1))/2;
            ans += num;
        }

        return ans;
    }
};