class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int a=0,b=0;
        int len = bank[0].size();
        int n = bank.size();
        for(int i=0; i<len; i++) {
            if(bank[0][i]=='1')
                a += 1;
        }
        int ans = 0;
        for(int i=1; i<n; i++) {
            b = 0;
            for(int j=0; j<len; j++) {
                if(bank[i][j]=='1')
                    b += 1;
            }
            cout << a << " " << b << endl;
            ans += a*b;
            if(b!=0) a = b;
            // cout << a << " " << b << endl;
        }
        return ans;
    }
};