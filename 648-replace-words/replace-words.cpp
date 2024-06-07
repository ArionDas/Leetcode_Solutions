class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> um;

        for(string i:dictionary) {
            um[i]++;
        }
        stack<string> st;
        int len = sentence.length();

        string str = "";
        for(int i=0; i<len; i++) {
            if(sentence[i]==' ') {
                //cout << str << endl;
                st.push(str);
                //i += 1;
                str = "";
                continue;
            }
            str += sentence[i];
        }
        st.push(str);
        //cout << str << endl;

        stack<string> st2;
        while(!st.empty()) {
            string str = st.top();
            st.pop();
            bool flag = 0;
            string str_ = "";
            for(int i=0; i<str.length(); i++) {
                str_ += str[i];
                if(um.find(str_)!=um.end()) {
                    st2.push(str_);
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                st2.push(str);
            }
        }

        string ans = "";
        while(!st2.empty()) {
            ans += st2.top();
            ans += " ";
            st2.pop();
        }

        ans = ans.substr(0,ans.length()-1);

        return ans;
    }
};