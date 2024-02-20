class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        int sum_req = n*(n+1)/2;
        for(auto i=0; i<n; i++){
            sum+=nums[i];
        }

        return (sum_req-sum);
    }
};