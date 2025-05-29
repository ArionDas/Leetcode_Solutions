class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        stack<int> st;
        int maxa = 0;

        int n = ht.size();
        for(int i=0; i<=n; i++) {
            while(!st.empty() && (i==n || ht[st.top()] >= ht[i])) {
                int height = ht[st.top()];
                st.pop();

                int width = 0;
                if(st.empty())
                    width = i;
                else {
                    width = i - st.top() - 1;
                }

                maxa = max(maxa, width * height);
            }
            st.push(i);
        }
        return maxa;
    }
};