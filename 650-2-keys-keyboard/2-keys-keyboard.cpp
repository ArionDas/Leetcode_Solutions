class Solution {
public:

    int solve(int n){
        int divisor = 2;
        int ans = 0;
        while(n>=2){
            while(n%divisor ==0){
                n = n/divisor;
                ans = ans + divisor;
            }
            divisor++;
        }
        return ans;
    }

    int minSteps(int n) {
        if(n==1){
            return 0;
        }

        return solve(n);
    }
};