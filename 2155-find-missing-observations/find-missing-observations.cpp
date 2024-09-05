class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total_sum = mean * (n+m);

        int sum_m = accumulate(rolls.begin(), rolls.end(), 0);
        int sum_n = total_sum - sum_m;

        if(n*6 < sum_n || n*1 > sum_n) {
            return {};
        }

        vector<int> rolls_n;
        int reg = sum_n / n;
        int sur = sum_n%n;

        for(int i=0; i<n; i++) {
            if(sur>0)
                rolls_n.push_back(reg+1);
            else
                rolls_n.push_back(reg);

            sur = max(0, sur-1);
        }

        return rolls_n;
    }
};