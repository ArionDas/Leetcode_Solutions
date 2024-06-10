class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> h2 = h;
        sort(h.begin(),h.end());

        int ans = 0;

        for(int i=0; i<h.size(); i++) {
            if(h2[i]!=h[i])
                ans += 1;
        }

        return ans;
    }
};