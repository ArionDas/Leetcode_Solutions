class Solution {
public:
    int minLength(string s) {
        stack <char> st;
        
        for(char x:s) {
            if(st.empty()) st.push(x);
            else {
                char tp = st.top();
                if(tp=='A'&&x=='B' || tp=='C'&&x=='D') st.pop();
                else st.push(x);
            }
        }
        return st.size();
    }
};