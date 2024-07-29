class Solution {
public:
    int numTeams(vector<int>& rating) {
        int total = 0;

        for(int i=0; i<rating.size(); i++) {
            int right_less = 0;
            int right_more = 0;
            int left_less = 0;
            int left_more = 0;

            for(int j=i+1; j<rating.size(); j++) {
                if(rating[j] < rating[i]) right_less += 1;
                else if (rating[i] < rating[j]) right_more += 1;
            }

            for(int j=0; j<i; j++) {
                if(rating[j] < rating[i]) left_less += 1;
                else if (rating[i] < rating[j]) left_more += 1;
            }

            total += right_less * left_more + right_more * left_less;
        }

        return total;
    }
};