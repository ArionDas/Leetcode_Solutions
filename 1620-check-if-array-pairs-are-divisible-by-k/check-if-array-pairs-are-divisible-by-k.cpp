class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> rem(k,0);
        for(auto it:arr) {
            int remainder = ((it % k) + k) % k;
            rem[remainder] += 1;
        }

        for(int i=1; i<k; i++) {
            if(rem[i] != rem[k-i]) {
                return false;
            }
        }

        if(rem[0] % 2 != 0) {
            return false;
        }

        return true;
    }
};