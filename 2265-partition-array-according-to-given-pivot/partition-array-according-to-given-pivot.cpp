class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> smaller, larger;
        int cnt = 0;
        for(auto it:nums) {
            if(it > pivot)
                larger.push_back(it);
            else if(it < pivot)
                smaller.push_back(it);
            else
                cnt += 1;
        }

        vector<int> ans;

        for(auto it:smaller) {
            ans.push_back(it);
        }

        while(cnt--) {
            ans.push_back(pivot);
        }

        for(auto it:larger) {
            ans.push_back(it);
        }

        return ans;
    }
};