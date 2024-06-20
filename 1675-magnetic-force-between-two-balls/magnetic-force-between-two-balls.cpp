class Solution {
public:
    // min or max within a bounded range => binary search
    
    int isValid(int mid, vector<int> position) {
        int total = 1;
        int currDist = position[0];
        for(int i=1; i<position.size(); i++) {
            if(position[i] - currDist >= mid) {
                total += 1;
                currDist = position[i];
            }
        }
        return total;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 0;
        int r = 1e9;

        int currMax = 0;
        while(l<=r) {
            int mid = l + (r-l)/2;

            if(isValid(mid, position) >= m) {
                l = mid + 1;
                currMax = max(currMax, mid);
            }
            else {
                r = mid - 1;
            }
        }
        return currMax;
    }
};