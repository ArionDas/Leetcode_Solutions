class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;

        unordered_map<int,int> um;
        for(int i=0; i<nums.size(); i++)
            um[nums[i]]++;

        int k=1;
        for(auto i=um.begin(); i!=um.end(); i++) {
            if(i->second==2) ans.push_back(i->first);
        }
        while(true) {
            if(um.find(k)==um.end()) {
                ans.push_back(k);
                break;
            }
            k++;
        }
        return ans;
    }
};