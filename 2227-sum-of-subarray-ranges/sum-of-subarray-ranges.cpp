class Solution {
public:

    long long mins(vector<int> nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nse(n, n);

        for(int i=0; i<n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        vector<int> pse(n, -1);

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i]) {
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long total = 0;
        for(int i=0; i<n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total += (long long)nums[i] * left * right;
        }

        return total;
    }

    long long maxs(vector<int> nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n, n);

        for(int i=0; i<n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                nge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        vector<int> pge(n, -1);

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                pge[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long total = 0;
        for(int i=0; i<n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total += (long long)nums[i] * left * right;
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return maxs(nums) - mins(nums);
    }
};