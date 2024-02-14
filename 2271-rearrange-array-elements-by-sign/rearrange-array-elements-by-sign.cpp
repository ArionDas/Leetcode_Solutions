class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);

        int neg=0;
        int pos=0;

        for(int i=0; i<n; i++) {
            if(nums[i]>0) {
                ans[2*pos] = nums[i];
                pos+=1;
            }
            else {
                ans[2*neg+1] = nums[i];
                neg+=1;
            }
        }
        return ans;
    }
};