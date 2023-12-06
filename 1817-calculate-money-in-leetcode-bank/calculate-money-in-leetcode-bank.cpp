class Solution {
public:
    int totalMoney(int n) {
        int i=1;
        int k=1;
        int ans=0;

        int j=1;

        while(i<=n) {

            if(i%7==0) {
                ans += j;
                k += 1;
                j = k;
            }
            else {
                ans += j;
                cout << j << " ";
                j += 1;
            }
            i += 1;

        }
        return ans;
    }
};