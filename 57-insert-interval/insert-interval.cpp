class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        int n = interval.size();
        int i=0;
        vector<vector<int>> res;

        while(i<n && newInterval[0] > interval[i][1]){
            res.push_back(interval[i]);
            i++;
        }

        while(i<n && newInterval[1] >= interval[i][0]){
            newInterval[0] = min(newInterval[0], interval[i][0]);
            newInterval[1] = max(newInterval[1], interval[i][1]);
            i++;
        }
        res.push_back(newInterval);

        while(i<n){
            res.push_back(interval[i]);
            i++;
        }
        return res;
    }
};