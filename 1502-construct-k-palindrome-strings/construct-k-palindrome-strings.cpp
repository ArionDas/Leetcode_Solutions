class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();

        if(n<k)
            return 0;

        vector<int> f(26, 0);
        for(auto it:s) {
            f[it-'a']++;
        }

        int cnt = 0;
        for(auto it:f) {
            if(it&1) {
                cnt += 1;
            }
        }

        if(cnt>k) 
            return 0;

        return 1;
    }
};