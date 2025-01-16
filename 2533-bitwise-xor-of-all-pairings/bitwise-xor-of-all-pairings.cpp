class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, long long> um;
        int n = nums1.size();
        int m = nums2.size();

        for(int i=0; i<n; i++) {
            um[nums1[i]] += m;
        }

        for(int i=0; i<m; i++) {
            um[nums2[i]] += n;
        }

        long long ans = 0;
        for(auto it:um) {
            if(it.second % 2 != 0) {
                ans ^= it.first;
            }
        }

        return ans;
    }
};