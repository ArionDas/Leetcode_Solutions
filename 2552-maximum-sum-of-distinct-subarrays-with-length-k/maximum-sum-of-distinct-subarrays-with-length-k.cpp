class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> um;
        int n = nums.size();
        int low = 0, high = 0;
        long long sum = 0;

        while(high < n) {

            um[nums[high]]++;
            sum += nums[high];

            if(high - low + 1 != k) {
                high += 1;
                continue;
            }
            else {
                if(um.size() == k)
                    ans = max(sum, ans);
                sum -= nums[low];
                um[nums[low]]--;
                if(um[nums[low]] == 0)
                    um.erase(nums[low]);
                low += 1;
            }
            //cout << ans << endl;
            high += 1;
        }

        return ans;
    }
};