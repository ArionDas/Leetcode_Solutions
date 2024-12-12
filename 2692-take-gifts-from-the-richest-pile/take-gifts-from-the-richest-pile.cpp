class Solution {
public:

    long long sq_root(int n) {
        long long low = 0;
        long long high = n;

        long long ans = 0;

        while(low<=high) {
            long long mid = low + (high-low) / 2;

            if(mid * mid < n) {
                ans = mid;
                low = mid+1;
            }
            else if(mid * mid > n){
                high = mid-1;
            }
            else {
                ans = mid;
                break;
            }
        }

        return ans;
    }

    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();

        priority_queue<int> pq;
        for(auto it:gifts)
            pq.push(it);

        long long ans = 0;
        while(k--) {
            int top = pq.top();
            long long sq = sq_root(top);
            pq.pop();
            pq.push(sq);
        }

        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};