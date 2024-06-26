class Solution {
public:

    void subsetsUtil(vector<int> &nums, vector<vector<int>> &res, vector<int> &subset, int index) {
        res.push_back(subset);

        for(int i=index; i<nums.size(); i++) {
            subset.push_back(nums[i]);

            subsetsUtil(nums, res, subset, i+1);

            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> res;

        int index = 0;
        subsetsUtil(nums, res, subset, index);

        return res;
    }
};