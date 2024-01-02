class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> um;

        for(int num:nums)
            um[num]++;

        vector<vector<int>> ans;
        int n = nums.size();
        int k = 0;

        while(k<n) {
            vector<int> temp;
            for(auto it=um.begin(); it!=um.end(); it++) {
                if(it->second>0) {
                    temp.push_back(it->first);
                    um[it->first]--;
                    // if(um[it->first] == 0){
                    //     um.erase(it->first);
                    // }
                    k += 1;
                }
                else {
                    //um.erase(it->first);
                    continue;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};