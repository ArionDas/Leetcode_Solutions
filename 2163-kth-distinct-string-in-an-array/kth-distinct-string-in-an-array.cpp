class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> um;
        queue<string> q;
        int i=0;
        int ke=k;
        int n = arr.size();
        for(; i<n; i++) {
            um[arr[i]]++;
        }

        string ans="";
        for(int i=0; i<n; i++) {
            if(um.find(arr[i])!=um.end() && um[arr[i]]==1)
                q.push(arr[i]);
        }

        if(q.size()<k)
            return "";

        while(k-- && !q.empty()) {
            ans = q.front();
            q.pop();
        }
        return ans;
    }
};