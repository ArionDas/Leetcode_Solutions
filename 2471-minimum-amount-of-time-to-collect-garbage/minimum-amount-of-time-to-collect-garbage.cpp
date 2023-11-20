class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        vector<int> travel_time(n,0);
        travel_time[0] = 0;
        for(int i=1; i<n; i++) {
            travel_time[i] = travel_time[i-1] + travel[i-1];
        }
        int cost = 0;
        // for(int i=1; i<n-1; i++) {
        //     travel[i] = travel[i-1] + travel[i];
        // }

        int metal=0, paper=0, glass=0;
        int gi=0, pi=0, mi=0;
        for(int i=0; i<n; i++) {
            cost += garbage[i].size();
            for(int j=0; j<garbage[i].size(); j++) {
                if(garbage[i][j]=='G') {
                    //glass += (travel_time[i]-travel_time[gi]);
                    gi = i;
                }
                else if(garbage[i][j]=='P') {
                    //paper += (travel_time[i]-travel_time[pi]);
                    pi = i;
                }
                else if(garbage[i][j]=='M') {
                    //metal += (travel_time[i]-travel_time[mi]);
                    mi = i;
                }
            }
        }
        int ans = travel_time[mi] + travel_time[pi] + travel_time[gi] + cost;
        return ans;
    }
};