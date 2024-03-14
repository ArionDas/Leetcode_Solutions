class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int> um;
        int n = nums.size()-1;
        if(n==0)
            return 0;
        for(int num:nums)
            um[num]++;

        for(int i=1; i<=n; i++) {
            if(i!=n) {
                if(um[i]!=1)
                    return false;
            }
            else if(i==n) {
                if(um[i]!=2)
                    return false;
            }
        }

        return true;
    }
};