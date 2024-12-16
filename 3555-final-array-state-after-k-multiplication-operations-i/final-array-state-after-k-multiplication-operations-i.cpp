class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mp) {
        int n = nums.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<n; i++) {
            pq.push(make_pair(nums[i], i));
        }

        while(k--) {
            pair<int,int> p = pq.top();
            pq.pop();

            int num = p.first * mp;
            int ind = p.second;

            pq.push(make_pair(num, ind));
        }

        vector<int> ans(n,0);
        while(!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();

            int ind = p.second;
            int num = p.first;

            ans[ind] = num;
        }

        return ans;
    }
};