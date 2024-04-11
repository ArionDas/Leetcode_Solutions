class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<int> st;
        int n = num.size(),i=0;
        if(n == k) return "0";
        string ans="";
        for(;i<n;i++){
            int ele = num[i]-'0';
            while(!st.empty() && k>0 && st.top() > ele){ 
                k--; 
                st.pop();
            }
            st.push(ele);
        }
        //if k not zero simply remove the stack top as we are storing mono increasing value
        while(!st.empty()){
            if(k==0){
                  ans += st.top()+'0';
            }else{
                k--;
            }
          st.pop();
        }
    
        reverse(ans.begin(),ans.end());
        i=0,n=ans.size();
        while(i<n && ans[i] == '0') i++;
        if(i == n) return "0"; //means all leading zeroes
        return ans.substr(i,n-i);
    }
};