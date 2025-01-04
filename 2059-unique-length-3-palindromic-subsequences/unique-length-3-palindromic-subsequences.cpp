class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<int,int> um;
        vector<int> st(26,-1);
        vector<int> en(26,-1);

        for(int i=0; i<n; i++) {
            if(um.find(s[i])==um.end())
                st[s[i]-'a'] = i;
            
            um[s[i]] += 1;
            en[s[i]-'a'] = i;
        }

        int ans = 0;

        for(int i=0; i<26; i++) {
            char ch = 'a' + i;
            if(en[i] != -1) {
                unordered_set<int> us;
                for(int j=st[i]+1; j<en[i]; j++) {
                    us.insert(s[j]);
                }
                ans += (us.size());
                cout << ans << endl;
            }
        }

        return ans;
    }
};