class Solution {
public:

    int merge(vector<vector<int>> &arr) {
        // Sort intervals based on start values
        sort(arr.begin(), arr.end());
    
        vector<vector<int>> res;
        res.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            vector<int>& last = res.back();
            vector<int>& curr = arr[i];

            // If current interval overlaps with the last merged
            // interval, merge them 
            if (curr[0] < last[1]) 
                last[1] = max(last[1], curr[1]);
            else 
                res.push_back(curr);
        }

        // cout << "hey" << endl;
        // for(auto it:res) {
        //     cout << it[0] << " " << it[1] << endl;
        // }

        return res.size();
    }

    bool checkValidCuts(int n, vector<vector<int>>& rect) {
        vector<vector<int>> hor, ver;
        
        for(int i=0; i<rect.size(); i++) {
            hor.push_back({rect[i][1], rect[i][3]});
            ver.push_back({rect[i][0], rect[i][2]});
        }

        if(merge(ver)>=3 || merge(hor)>=3)
            return 1;
        
        return 0;
    }
};