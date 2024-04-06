class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int n = s.length();
        int cnt = 0;
        string ans = "";
        for(int i=0; i<n; i++) {
            if(s[i]!='(' && s[i]!=')') {
                ans += s[i];
                continue;
            }
            else if(s[i]=='(') {
                st.push(s[i]);
                ans += s[i];
                cnt += 1;
            }
            else {
                if(!st.empty()) {
                    st.pop();
                    ans += s[i];
                    //s.erase(i,1);
                }
                else {
                    //s.erase(i,1);
                    continue;
                }
            }
            //cout << ans << endl;
        }
        n = ans.length();
        for(int i=n-1; i>=0 && !st.empty(); i--) {
            if(ans[i]=='(') {
                //s.erase(i,1);
                ans.erase(i,1);
                st.pop();
            }
        }

        return ans;
    }
};