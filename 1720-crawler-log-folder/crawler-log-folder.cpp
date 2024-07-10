class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        int len = logs.size();
        int i=0;
        while(i<len) {
            if(logs[i][0]!='.') {
                depth += 1;
            }
            else if(logs[i][1]=='.') {
                depth -= 1;
                depth = max(depth, 0);
            }
            else
                depth = depth;

            i += 1;
        }

        return depth;
    }
};