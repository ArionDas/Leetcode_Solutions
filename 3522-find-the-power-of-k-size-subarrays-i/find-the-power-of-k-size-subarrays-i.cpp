class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;

        vector<int> ans;

        while(j<n) {
            if(j-i+1 != k) {
                j += 1;
            }
            else {
                int a = i;
                int b = j;
                int maxi = nums[a];
                bool f = 1;
                for(int l=a+1; l<=b; l++) {
                    if(nums[l] <= nums[l-1] || nums[l]-nums[l-1] != 1) {
                        ans.push_back(-1);
                        f=0;
                        break;
                    }
                    else {
                        maxi = max(maxi, nums[l]);
                    }
                }
                if(f) {
                    ans.push_back(maxi);
                }
                i += 1;
                j += 1;
            }
        }

        return ans;
    }
};