class Solution {
public:
    int climbStairs(int n) {
        int i=2;
        int prev_one = 1;
        int prev_two = 1;
        for(; i<=n; i++) {
            int curr = prev_one + prev_two;
            prev_two = prev_one;
            prev_one = curr;
        }

        return prev_one;
    }
};