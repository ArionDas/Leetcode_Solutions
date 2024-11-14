class Solution {
public:

    int check_value(int mid, vector<int>& q, int n) {
        long long count = 0;
        for(int i=0; i<n; i++) {
            count += ceil((1.0 * q[i]) / mid);
        }
        return count;
    }

    int minimizedMaximum(int n, vector<int>& q) {
        int size = q.size();
        int mini = 1;
        int maxi = *max_element(q.begin(), q.end());
        int ans = 0;

        while(mini<=maxi) {
            int mid = mini + (maxi - mini)/2;

            if(check_value(mid, q, size) > n) {
                mini = mid+1;
            }
            else if(check_value(mid, q, size) <= n) {
                ans = mid;
                maxi = mid-1;
            }
        }
        return ans;
    }
};