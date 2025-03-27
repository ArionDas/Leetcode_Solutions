class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int req;
        unordered_map<int, int> um;
        for(auto it:nums) {
            um[it] += 1;
            if(um[it] > n/2) {
                req = it;
                //break;
            }
        }

        int freq = um[req];

        int j = 0;
        int cnt = 0;
        while(j<n) {
            if(nums[j]==req) {
                cnt += 1;
            }
            if(cnt > (j+1)/2 && (freq-cnt) > (n-j-1)/2) {
                return j;
            }
            j += 1;
        }

        return -1;
    }
};