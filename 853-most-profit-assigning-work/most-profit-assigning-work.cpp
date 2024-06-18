class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int len = difficulty.size();
        int m = worker.size();
        vector<pair<int,int>> vp(len);

        for(int i=0; i<len; i++) {
            vp[i].first = difficulty[i];
            vp[i].second = profit[i];
        }
        sort(vp.begin(), vp.end());
        sort(worker.begin(),worker.end());

        int ans = 0;
        int j = 0;
        int i = 0;
        int maxp=0, bestp=0;
        for(i=0; i<m; i++) {
            while(j<len && worker[i] >= vp[j].first) {
                bestp = max(bestp,vp[j].second);
                j += 1;
            }
            maxp += bestp;
        }
        return maxp;
    }
};