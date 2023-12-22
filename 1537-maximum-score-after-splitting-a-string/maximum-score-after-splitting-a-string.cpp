class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        
        vector<int> zeros(n,0);
        vector<int> ones(n,0);

        if(s=="00") return 1;
        if(s=="01") return 2;
        if(s=="11") return 1;

        if(s[0]=='0') zeros[0] = 1;
        if(s[n-1]=='1') ones[n-1] = 1;

        for(int i=1; i<n; i++) {
            if(s[i]=='0')
                zeros[i] = zeros[i-1] + 1;
            else
                zeros[i] = zeros[i-1];
        }

        for(int i=n-2; i>=0; i--) {
            if(s[i]=='1')
                ones[i] = ones[i+1] + 1;
            else
                ones[i] = ones[i+1];
        }

        int ans = 0;
        for(int i=1; i<n-1; i++) {
            ans = max(ans,ones[i]+zeros[i]);
        }
        return ans;
    }
};