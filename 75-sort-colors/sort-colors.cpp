class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size()-1;

        while(mid<=high) {
            if(nums[mid]==0) { // nums[mid]=0
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1) // nums[mid]=1
                mid++;
            else { // nums[mid]=2
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};