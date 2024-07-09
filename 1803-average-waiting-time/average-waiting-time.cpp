class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double time = 0;

        int i=1;
        int len = customers.size();
        //double time = 0;

        int start = 1;
        //int end = customers[0][0] + customers[0][1];
        //time += customers[0][1];
        int available_at = 0;
        for (auto& customer : customers) {
            int arrival = customer[0], t = customer[1];
            available_at = max(available_at, arrival) + t;
            time += available_at - arrival;
        }

        //cout << time << endl;
        return double((time*1.0)/len);
    }
};