class Solution {
public:
    int trap(vector<int>& ht) {
        int left = 0;
        int right = ht.size()-1;
        int res = 0;
        int maxleft = 0, maxright = 0;

        while(left <= right) {
            if(ht[left] <= ht[right]) {
                if(ht[left] >= maxleft) {
                    maxleft = ht[left];
                }
                else {
                    res += maxleft - ht[left];
                }
                left += 1;
            }
            else {
                if(ht[right] >= maxright) {
                    maxright = ht[right];
                }
                else {
                    res += maxright - ht[right];
                }
                right-=1;
            }
        }
        return res;
    }
};