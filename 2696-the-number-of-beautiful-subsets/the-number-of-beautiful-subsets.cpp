class Solution {
public:
    int ans=0;
    unordered_map<int,int> rec;

    void recursion(int pos, int n, vector<int>& tmp, vector<int>& nums, int k) {
        if(pos==n) {
            ans += 1;
            return;
        }

        if(rec[nums[pos]-k]==0) {
            rec[nums[pos]]++;
            recursion(pos+1, n, tmp, nums, k);
            rec[nums[pos]]--;
        }

        recursion(pos+1, n, tmp, nums, k);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        ans = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            rec[nums[i]]++;
            recursion(i+1, n, tmp, nums, k);
            rec[nums[i]]--;
        }
        return ans;
    }
};