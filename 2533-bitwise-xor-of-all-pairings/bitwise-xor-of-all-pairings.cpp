class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        //unordered_map<int, long long> um;
        int n = nums1.size();
        int m = nums2.size();
        int x1=0, x2=0;

        for(int i=0; i<n; i++) {
            x1 ^= nums1[i];
        }

        for(int i=0; i<m; i++) {
            x2 ^= nums2[i];
        }

        long long ans = 0;
        if(n&1) {
            ans ^= x2;
        }
        if(m&1) {
            ans ^= x1;
        }

        return ans;
    }
};