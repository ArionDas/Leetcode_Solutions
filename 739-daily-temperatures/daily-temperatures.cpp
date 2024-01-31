class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n);
        stack<int> st;
        reverse(t.begin(),t.end());

        ans[0] = 0;
        st.push(0);

        for(int i=1; i<n; i++) {
            while(!st.empty() && t[i]>=t[st.top()])
                st.pop();
            if(st.empty()) ans[i] = 0;
            else ans[i] = i-st.top();

            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};