class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        map<int, int> s1, s2;
        int n = nums.size();

        for(auto it:nums) {
            //s1.insert(it);
            s2[it] += 1;
        }

        int j = 0;
        while(j<n) {
            s1[nums[j]] += 1;
            s2[nums[j]] -= 1;

            if(s2[nums[j]] == 0) {
                s2.erase(nums[j]);
            }

            //cout << s1.size() << " " << s2.size() << endl;

            if(s1.rbegin()->first <= s2.begin()->first) {
                return j+1;
            }
            j += 1;
        }

        return n;
    }
};