class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len = nums.size();

        unordered_map<int,int> um;

        for(int num:nums)
            um[num]++;

        int ans = 0;
        for(auto it=um.begin(); it!=um.end(); it++) {
            if(it->second==1)
                return -1;
            else if(it->second%3==0)
                ans += it->second/3;
            else if(it->second%2==0) {
                while(it->second>0) {
                    ans += 1;
                    it->second -= 2;
                    if(it->second%3==0) {
                        ans += it->second/3;
                        break;
                    }
                }
            }
            else {
                while(it->second>0) {
                    ans += 1;
                    it->second -= 2;
                    if(it->second%3==0) {
                        ans += it->second/3;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};