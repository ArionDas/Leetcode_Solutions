class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> m;

        for(int i=0; i<names.size(); i++) {
            m[heights[i]] = names[i];
        }

        vector<string> ans;

        for(auto i=m.begin(); i!=m.end(); i++) {
            ans.push_back(i->second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};