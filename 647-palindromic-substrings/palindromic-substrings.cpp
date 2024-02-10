class Solution {
public:

    int palindrome_check(string s, int left, int right) {
        int count = 0;
        while(left>=0 && right<s.length() && s[left]==s[right]) {
            left -= 1;
            right += 1;
            count += 1;
        }
        return count;
    }

    int countSubstrings(string s) {
        int n = s.length(), ans = 0;

        for(int i=0; i<n; i++) {
            int even = palindrome_check(s, i, i+1);
            int odd = palindrome_check(s, i, i);
            ans += (odd+even);
        }
        return ans;
    }
};