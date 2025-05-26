class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int,int>>st;
        int MOD=1e9+7;
        int s=0,n=arr.size();
        vector<int>nse(n,n); 
        vector<int>pse(n,-1);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().second > arr[i]) st.pop();
            if(!st.empty()) nse[i]=st.top().first;
            st.push({i,arr[i]});
        }

        while(!st.empty()) st.pop();

        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().second >= arr[i]) st.pop();
            if(!st.empty()) pse[i]=st.top().first;
            st.push({i,arr[i]});
        }

        for(int i=0;i<n;i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long temp = ((left * right) % MOD * arr[i]) % MOD;
            s = (s + temp) % MOD;
        }
        return s;
    }
};