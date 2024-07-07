class Solution {
public:

    int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<int> prev(tar+1,0);
    
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(tar+1,0);
        for(int target= 0; target<=tar; target++){
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= (notTaken + taken);
        }
        prev = cur;
    }
    return prev[tar];
}


    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = 0;
        int len = nums.size();
        for(int i=0; i<len; i++) {
            totalsum += nums[i];
        }

        if(totalsum-target < 0 || (totalsum-target)%2) return 0;

        return findWays(nums, (totalsum-target)/2);
    }
};