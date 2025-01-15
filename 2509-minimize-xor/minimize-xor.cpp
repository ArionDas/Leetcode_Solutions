class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count_set_bits_1 = 0, count_set_bits_2 = 0;
        int n1 = num1, n2 = num2;
        while(n2) {
            count_set_bits_2 += (n2&1);
            n2 >>= 1;
        }

        while(n1) {
            count_set_bits_1 += (n1&1);
            n1 >>= 1;
        }

        if(count_set_bits_1 == count_set_bits_2) {
            return num1;
        }

        if(count_set_bits_2 > count_set_bits_1) {
            int ans = num1;
            int diff = count_set_bits_2 - count_set_bits_1;
            while(diff--) {
                ans = ans | (ans+1);
            }
            return ans;
        }

        int ans = num1;
        int diff = count_set_bits_1 - count_set_bits_2;
        while(diff--) {
            ans = ans & (ans-1);
        }

        return ans;
    }
};