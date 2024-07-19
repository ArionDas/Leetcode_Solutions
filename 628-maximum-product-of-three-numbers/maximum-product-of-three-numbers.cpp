class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();

        int prod_neg = nums[0]*nums[1];
        int prod_pos = nums[len-2]*nums[len-1];
        int case1=INT_MIN, case2=INT_MIN;

        //if(prod_neg > prod_pos) {
            case1 = prod_neg * nums[len-1];
        //}
        //else {
            case2 = prod_pos * nums[len-3];
        //}
        return max(case1, case2);
    }
};