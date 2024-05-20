class Solution {
public:

    void find_answer(vector<int> &num, int index, vector<int>& nums, int size, int &ans) {
        if(index>=size) {
            int xorr = 0;
            for(int i:num) {
                xorr = xorr^i;
            }
            ans += xorr;
            return;
        }

        //for(int i=index; i<size; i++) {
            num.push_back(nums[index]);
            find_answer(num, index+1, nums, size, ans);
            num.pop_back();
            find_answer(num, index+1, nums, size, ans);
        //}
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int> num;
        int n = nums.size();
        int ans = 0;
        find_answer(num, 0, nums, n, ans);
        return ans;
    }
};