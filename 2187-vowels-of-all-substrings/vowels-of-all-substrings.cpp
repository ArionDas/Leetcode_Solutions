class Solution {
public:
    long long countVowels(string word) {
        int n = word.size();
        long long ans = 0;
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};

        for(int i=0; i<n; i++) {
            if(v.count(word[i]))
                ans += (long long)(i+1) * (long long)(n-i);
        }

        return ans;
    }
};