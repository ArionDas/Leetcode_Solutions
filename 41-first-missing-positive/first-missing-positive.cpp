class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int,int> m;

        for(auto i=0; i<nums.size(); i++)
            m[nums[i]]++;

        int k=1;
        for(auto i=m.begin(); i!=m.end(); i++, k++) {
            if(m.find(k)!=m.end()) {
                m[k]--;
            }
            else
                break;
        }
        return k;
    }
};