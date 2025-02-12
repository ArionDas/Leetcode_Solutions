class Solution {
public:

    int find_dig_sum(int num) {
        int sum = 0;

        while(num) {
            sum += num%10;
            num /= 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> ump;

        for(auto it:nums) {
            int sum = find_dig_sum(it);
            ump[sum].push(it);
        }

        int max_sum = -1;

        for(auto it:ump) {
            priority_queue<int> pq = it.second;
            //cout << it.first << " " << pq.size() << endl;
            if(pq.size() > 1) {
                int a = pq.top();
                pq.pop();
                int b = pq.top();
                max_sum = max(max_sum, a+b);
            }
        }

        return max_sum;

    }
};