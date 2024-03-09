class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> um;

        for(int num:nums1)
            um[num]++;

        for(int num:nums2) {
            if(um.find(num)!=um.end())
                return num;
        }
        return -1;
    }
};