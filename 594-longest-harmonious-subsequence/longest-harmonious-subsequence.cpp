class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int l=0,r=0;

        int maxlen=0;

        while(r<n){
            while(nums[r]-nums[l]>1){     //shrink the window if the difference between maximum and minimum element is greater than 1
                l++;
            }

            int len=r-l+1;

            // Only consider windows where the difference is exactly 1
            if (nums[r] - nums[l] == 1) {
                maxlen = max(maxlen,len);
            }

            r++;
        }

        return maxlen;
    }
};