class Solution {
public:

    void find_unique_subsets(int ind, vector<int> &nums, vector<int>& sbs, vector<vector<int>> &ans) {
        // if(ind==nums.size()){
        //     ans.push_back(sbs);
        //     return;
        // }
        ans.push_back(sbs);
        for(int i=ind; i<nums.size(); i++) {
            if(i>ind && nums[i]==nums[i-1]) continue;

            sbs.push_back(nums[i]);
            find_unique_subsets(i+1, nums, sbs, ans);
            sbs.pop_back();

            //find_unique_subsets(ind+1, nums, sbs, ans);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sbs;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        find_unique_subsets(0, nums, sbs, ans);
        return ans;
    }
};