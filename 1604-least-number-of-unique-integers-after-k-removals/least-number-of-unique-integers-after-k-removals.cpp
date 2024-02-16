class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> um;
        vector<int> v;

        for(int num:arr)
            um[num]++;

        for(auto it:um)
            v.push_back(it.second);

        sort(v.begin(), v.end());

        int ans = v.size();
        int n = ans;
        for(int i=0; i<n; i++) {
            if(v[i]<=k) {
                ans -= 1;
                k -= v[i];
            }
            else {
                break;
            }
        }

        return ans;
    }
};