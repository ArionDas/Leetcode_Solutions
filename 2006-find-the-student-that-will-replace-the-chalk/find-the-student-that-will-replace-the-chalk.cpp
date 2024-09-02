class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        int length = chalk.size();
        
        for(int i=0; i<length; i++) {
            sum += chalk[i];
        }

        k = k%sum;
        for(int i=0; i<length; i++) {
            k -= chalk[i];
            if(k<0) {
                return i;
            }
        }

        return 0;
    }
};