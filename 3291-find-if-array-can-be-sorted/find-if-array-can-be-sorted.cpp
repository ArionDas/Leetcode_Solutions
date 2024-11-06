class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> num2(len, 0);
        
        for(int i=0; i<len; i++) {
            int temp = nums[i];
            int count = 0;
            while(temp) {
                if(temp&1)
                    count += 1;
                temp /= 2;
            }
            num2[i] = count;
        }
        
        for(int i=0; i<len; i++) {
            for(int j=0; j<len-1; j++) {
                if(nums[j+1]<nums[j]) {
                    if(num2[j]==num2[j+1]) {
                        swap(nums[j],nums[j+1]);
                    }
                }
                else
                    continue;
            }
        }
        
        for(int i=0; i<len-1; i++)
            if(nums[i]>nums[i+1])
                return 0;
        
        return 1;
        
    }
};