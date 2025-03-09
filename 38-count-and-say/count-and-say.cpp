class Solution {
public:

    string find_RLE(string num) {
        int i=0;
        int cnt = 0;
        int len = num.length();
        string rle = "";

        if(len == 1) {
            rle += "1";
            rle += num[0];
            //cout << rle << endl;
            return rle;
        }

        while(i<len) {
            if(i==0) {
                cnt += 1;
                i += 1;
                continue;
            }
            if(num[i] != num[i-1]) {
                rle += to_string(cnt);
                cnt = 1;
                rle += num[i-1];
            }
            else {
                cnt += 1;
            }
            i += 1;
        }

        //if(cnt != 1) {
            rle += to_string(cnt);
            rle += num[len-1];
        //}

        //cout << rle << endl;
        return rle;
    }

    string countAndSay(int n) {
        string ans = "1";
        int cnt = 1;

        if(n == 1)
            return "1";

        int i = 1;
        while(i<n) {
            ans = find_RLE(ans);
            i += 1;
        }

        return ans;
    }
};