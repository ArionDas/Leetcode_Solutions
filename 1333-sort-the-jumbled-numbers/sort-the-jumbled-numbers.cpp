class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, pair<int,int>> mpp;

        int i=0;

        for(int it:nums) {
            int temp = it;
            int mapped_number = 0;

            int k=0;

            if(it==0) {
                mpp[it] = {mapping[it], i};
                i += 1;
            }
            else {
                while(temp > 0) {
                    int digit = temp%10;
                    digit = mapping[digit];
                    mapped_number = mapped_number + (digit * pow(10, k));
                    k += 1;
                    temp /= 10;
                }
                mpp[it] = {mapped_number, i};
                i += 1;
            }
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (mpp[a].first != mpp[b].first) {
                return mpp[a].first < mpp[b].first;
            } else {
                return mpp[a].second < mpp[b].second;
            }
        });

        return nums;
    }
};