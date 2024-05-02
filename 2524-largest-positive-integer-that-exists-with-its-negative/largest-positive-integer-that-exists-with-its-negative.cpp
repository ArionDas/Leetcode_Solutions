class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int> m;

        for(auto i=0; i<nums.size(); i++) {
            m[nums[i]]++;
        }

        int maxi = 0;

        for(auto i=0; i<nums.size(); i++) {
            if(m.find((-1)*nums[i])!=m.end())
                maxi = max(maxi,nums[i]);
        }
        if(maxi==0)
            return -1;
        return maxi;
    }
};