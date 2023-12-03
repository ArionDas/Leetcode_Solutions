class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int len = points.size();
        int x = points[0][0];
        int y = points[0][1];
        for(int i=1; i<len; i++) {
            int diffx = abs(points[i][0]-x);
            x = points[i][0];
            int diffy = abs(points[i][1]-y);
            y = points[i][1];

            if(diffx==0) {
                ans += diffy;
            }
            else if(diffy==0) {
                ans += diffx;
            }
            else {
                ans += max(diffx,diffy);
            }
        }
        return ans;
    }
};