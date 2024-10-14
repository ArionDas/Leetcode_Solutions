class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();

        for(int num:nums) {
            pq.push(num);
        }

        long long ans = 0;
        while(k--) { 
            int num = pq.top();
            pq.pop();
            ans += num;
            num = ceil(1.0 * num/3);
            pq.push(num);
        }

        return ans;
    }
};