class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        //int i=0;
        int j=0;
        int len=grumpy.size();
        vector<int> temp = customers;
        int ans = 0;
        for(int i=0; i<len; i++) {
            if(grumpy[i]==0) {
                ans += temp[i];
                temp[i] = 0;
            }
        }
        int maxsum = 0, sum = 0;
        int k = 0;
        while(j<len) {
            sum += temp[j];
            if(j-k+1 == minutes) {
                maxsum = max(maxsum, sum);
                sum -= temp[k];
                k += 1;
            }
            j += 1;
        }
        ans += maxsum;
        return ans;
    }
};