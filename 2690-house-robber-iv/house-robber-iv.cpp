class Solution {
public:

    bool can_steal(const vector<int>& nums, int k, int cap) {
        int count = 0;
        int i = 0;

        while(i < nums.size()) {
            if(nums[i] <= cap) {
                count += 1;
                i += 2;
            }
            else {
                i += 1;
            }
        }

        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while(left < right) {
            int mid = left + (right - left) / 2;
            if(can_steal(nums, k, mid))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};