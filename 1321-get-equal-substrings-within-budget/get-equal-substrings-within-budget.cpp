class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        int low = 0;
        int curr_cost = 0;
        int max_length = 0;
        //vector<int> cost(len,0);

        for(int high=0; high<len; high++) {
            curr_cost += abs(s[high]-t[high]);

            while(curr_cost > maxCost) {
                curr_cost -= abs(s[low]-t[low]);
                low += 1;
            }

            max_length = max(max_length, high-low+1);
        }
        return max_length;
    }
};