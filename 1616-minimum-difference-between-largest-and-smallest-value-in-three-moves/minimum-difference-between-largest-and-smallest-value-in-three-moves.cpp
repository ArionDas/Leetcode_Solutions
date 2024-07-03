class Solution {
public:
    int minDifference(vector<int>& nums) {
        int len = nums.size();

        if(len<=4)
            return 0;

        sort(nums.begin(),nums.end());
        int ans = INT_MAX;

        int maxi = *max_element(nums.begin(),nums.end()-3);
        int mini = *min_element(nums.begin(),nums.end()-3);
        ans = min(ans,maxi-mini);

        maxi = *max_element(nums.begin()+3,nums.end());
        mini = *min_element(nums.begin()+3,nums.end());
        ans = min(ans,maxi-mini);

        maxi = *max_element(nums.begin()+2,nums.end()-1);
        mini = *min_element(nums.begin()+2,nums.end()-1);
        ans = min(ans,maxi-mini);

        maxi = *max_element(nums.begin()+1,nums.end()-2);
        mini = *min_element(nums.begin()+1,nums.end()-2);
        ans = min(ans,maxi-mini);

        return ans;
    }
};