class Solution {
public:
    int tribonacci(int n) {
        //int m = n+3;
        int terms[40] = {0};
        terms[0] = 0, terms[1] = 1, terms[2] = 1;
        int i = 3;
        while(i<=n) {
            terms[i] = terms[i-1] + terms[i-2] + terms[i-3];
            i += 1;
        }

        return terms[n];
    }
};