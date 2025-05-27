class Solution {
public:
    int differenceOfSums(int n, int m) {
        int q = n/m;
        int num2 = q*(q+1)/2*m;
        int num1 = n*(n+1)/2 - num2;

        return num1-num2;
    }
};