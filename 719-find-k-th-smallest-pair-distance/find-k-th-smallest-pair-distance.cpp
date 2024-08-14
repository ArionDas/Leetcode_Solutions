class Solution {
public:

    int countPairs(vector<int>& nums, int distance) {
        int count = 0, left = 0;
        for(int right = 1; right < nums.size(); right++) {
            while(left < right && nums[right] - nums[left] > distance) {
                left += 1;
            }
            count += (right - left);
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1];

        while(low < high) {
            int mid = low + (high - low) / 2;
            if(countPairs(nums, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};