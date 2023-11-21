class Solution {
public:

    int rev(int num) {
        int r = 0;
        int d = 0;
        while(num) {
            d = num%10;
            r = r*10+d;
            num = num/10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> um;
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            int temp = nums[i]-rev(nums[i]);
            if(um.find(temp)!=um.end()) {
                ans = (ans + um[temp])%1000000007;
            }
            um[temp]++;
        }
        return ans;
    }
};