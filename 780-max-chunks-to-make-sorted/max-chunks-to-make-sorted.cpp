class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int res = 0; int diff = 0;
        for(int i=0; i<n; i++) {
            diff += (arr[i] - i);
            res += (diff == 0);
        }
        return res;
    }
};