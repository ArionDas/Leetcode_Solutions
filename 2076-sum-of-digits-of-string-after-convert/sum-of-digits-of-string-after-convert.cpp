class Solution {
public:
    int getLucky(string s, int k) {
        //k--;
        int sum = 0;
        string ssum = "";
        for(int i=0; i<s.length(); i++) {
            int d = (s[i]-'a' + 1);
            ssum = ssum + to_string(d);
        }
        //cout << ssum << endl;
        for(int i=0; i<ssum.length(); i++) {
            sum += (ssum[i] - '0');
        }
        k--;
        int new_sum = 0;
        while(k--) {
            new_sum = 0;
            while(sum>0) {
                int d = sum%10;
                new_sum += d;
                sum = sum/10;
            }
            sum = new_sum;
            if(sum<10)
                return sum;
        }

        return sum;
    }
};