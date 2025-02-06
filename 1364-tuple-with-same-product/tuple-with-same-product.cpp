class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> um;
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                um[nums[i] * nums[j]] += 1;
            }
        }

        for(auto it:um) {
            if(it.second > 1) {
                int num = it.second;
                int req = num * (num-1) / 2;
                ans += req * 8;
            }
        }

        return ans;

    }
};