class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0);
        int n = s.length();
        int left = 0;
        int ans = 0;

        for(int i=0; i<n; i++) {
            count[s[i] - 'a'] += 1;

            while(count[0] > 0 && count[1] > 0 && count[2] > 0) {
                ans += (n-i);
                count[s[left] - 'a'] -= 1;
                left += 1;
            }
        }

        return ans;
    }
};