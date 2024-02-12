class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();

        int cnt=0;
        int el;
        for(int i=0; i<len; i++) {
            if(cnt==0) {
                cnt=1;
                el = nums[i];
            }
            else if(nums[i]==el) cnt++;
            else cnt--;
        }
        return el;
        // int cnt1=0;
        // for(int i=0; i<len; i++) {
        //     if(nums[i]==el)
        //         cnt1++;
        // }

        // if(cnt1>len/2) return el;
        // return -1;
    }
};