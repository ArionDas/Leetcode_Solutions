class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> pre(n, 0);
        vector<int> suf(n, 0);

        int add = 0;
        int moves = 0;
        for(int i=0; i<n; i++) {
            if(boxes[i] != '0') {
                moves += (add);
                pre[i] = moves;
                add += 1;
            }
            else {
                moves += (add);
                pre[i] = moves;
            }
        }
        add = 0;
        moves = 0;
        for(int i=n-1; i>=0; i--) {
            if(boxes[i] != '0') {
                moves += (add);
                suf[i] = moves;
                add += 1;
            }
            else {
                moves += (add);
                suf[i] = moves;
            }
        }

        vector<int> ans(n, 0);
        for(int i=0; i<n; i++) {
            ans[i] = pre[i] + suf[i];
        }

        return ans;
    }
};