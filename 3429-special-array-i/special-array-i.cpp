class Solution {
public:

    bool check(int a, int b) {
        return ((a%2==0 && b%2!=0) || (a%2!=0 && b%2==0));
    }

    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        for(int i=1; i<n; i++) {
            //cout << i << endl;
            if(!check(nums[i-1], nums[i]))
                return 0;
        }

        return 1;
    }
};