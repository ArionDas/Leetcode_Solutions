class Solution {
public:
    int maxCount(vector<int>& nums, int n, int maxSum) {
        long long sum = 0;
        int count = 0;

        unordered_map<int,int> um;
        for(auto it:nums) { 
            um[it]++;
        }

        int k = 1;
        while(k<=n) {
            if(um.find(k)==um.end()) {
                sum += k;
                if(sum <= maxSum)
                    count += 1;
                else
                    break;
            }
            //cout << count << " " << sum << endl;
            k += 1;
        }

        return count;
    }
};