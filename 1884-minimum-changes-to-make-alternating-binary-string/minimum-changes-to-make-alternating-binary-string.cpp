class Solution {
public:
    int minOperations(string s) {
        int ans = INT_MAX;
        int len = s.length();
        int count = 0;
        string s2 = s;
        for(int i=0; i<len; i++) {
            if(i%2==0 && s[i]=='1') count += 1;
            if(i%2==1 && s[i]=='0') count += 1;
        }

        return min(count, len-count);
        // for(int i=len-2; i>=0; i--) {
        //     if(s[i]=='0' && s[i+1]=='0') {
        //         opb += 1;
        //         s[i] = '1';
        //     }
        //     else if(s[i]=='1' && s[i+1]=='1') {
        //         opb += 1;
        //         s[i] = '0';
        //     }
        //     cout << "opb = " << opb << endl;
        // }

        //ans = min(opf,opb);
        return ans;
    }
};