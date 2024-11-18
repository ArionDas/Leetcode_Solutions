class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans;

        if(k==0) {
            ans.resize(n,0);
            return ans;
        }

        int sum = 0;
        bool parity = 0;
        if(k>0)
            parity = 1;

        k = abs(k);

        for(int i=0; i<n; i++) {
            if(parity) {
                //int steps = k;
                int sum = 0;
                int j = i+1;
                int steps = 0;
                while(steps<k) {
                    sum += code[j%n];
                    steps += 1;
                    j += 1;
                }
                ans.push_back(sum);
            }
            else {
                int sum = 0;
                int j = i-1;
                int steps = 0;
                while(steps<k) {
                    if(j<0)
                        j = n-1;
                    sum += code[j%n];
                    j -= 1;
                    steps += 1;
                }
                ans.push_back(sum);
            }
        }

        return ans;
    }
};