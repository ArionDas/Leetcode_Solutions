class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1)
            return 0;

        sort(intervals.begin(), intervals.end(), [](auto const &a, auto const &b) {return a[1] < b[1];});

        vector<int> curr = intervals[0];
        int count = 1;

        for(int i=1; i<n; i++) {
            if(intervals[i][0] >= curr[1]) {
                count += 1;
                curr = intervals[i];
            }
        }

        return (n-count);
    }
};