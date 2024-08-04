class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;

        for(int i=0; i<n; i++) {
            long long curr = 0;
            for(int j=i; j<n; j++) {
                curr += nums[j];
                sums.push_back(curr);
            }
        }
        sort(sums.begin(), sums.end());
        long long sum = 0;

        while(left <= right) {
            if(right != left)
                sum += (sums[left-1] + sums[right-1]);
            if(right == left)
                sum += sums[left-1];
            
            right -= 1;
            left += 1;
        }

        int res = sum % 1000000007;
        return res;
    }
};