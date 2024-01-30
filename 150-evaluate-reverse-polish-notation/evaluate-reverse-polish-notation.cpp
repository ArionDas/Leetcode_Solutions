class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> st;
        int a=0,b=0;
        for(int i=0; i<t.size(); i++) {
            if(t[i]!="+" && t[i]!="-" && t[i]!="*" && t[i]!="/")
                st.push(stoi(t[i]));
            else {
                a = st.top();st.pop();
                b = st.top();st.pop();

                if(t[i] == "+")
                    st.push(a+b);
                else if(t[i] == "-")
                    st.push(b-a);
                else if(t[i] == "*")
                    st.push(a*b);
                else
                    st.push(b/a);

                cout << st.top() << " ";
            }
        }

        return st.top();
    }
};