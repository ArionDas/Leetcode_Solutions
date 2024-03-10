class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> m; unordered_set<int> s;

        for(int i=0; i<nums1.size(); i++) m[nums1[i]]++;

        for(int i=0; i<nums2.size(); i++) {
            if(m.find(nums2[i])!=m.end())
                s.insert(nums2[i]);
        }

        for(auto i=s.begin(); i!=s.end(); i++) ans.push_back(*i);
        return ans;
    }
};