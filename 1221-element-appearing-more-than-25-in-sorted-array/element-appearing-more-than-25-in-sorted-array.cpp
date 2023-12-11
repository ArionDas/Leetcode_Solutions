class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> um;

        for(int i=0; i<arr.size(); i++)
            um[arr[i]]++;
        
        int req = arr.size()/4;
        int ans=0;
        for(auto it=um.begin(); it!=um.end(); it++) {
            if(it->second > req) {
                ans = it->first;
                break;
            }
        }
        return ans;
    }
};