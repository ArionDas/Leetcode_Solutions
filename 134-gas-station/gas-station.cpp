class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        
        int tg = 0;
        int tc = 0;
        int total = 0;
        int start_ind = 0;

        for(int i=0; i<len; i++) {
            tg += gas[i];
            tc += cost[i];
        }

        if(tg < tc) return -1;

        for(int i=0; i<len; i++) {
            total += (gas[i] - cost[i]);

            if(total < 0) {
                total = 0;
                start_ind = i + 1;
            }
        }

        return start_ind;
    }
};