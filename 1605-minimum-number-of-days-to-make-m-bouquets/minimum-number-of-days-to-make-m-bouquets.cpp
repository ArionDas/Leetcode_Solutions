class Solution {
public:
    int minDays(vector<int>& bloom, int m, int k) {
        int number_of_flowers = bloom.size();
        int l=1, h=1e9;
        if(number_of_flowers/k < m)
            return -1;
        while(l<h) {
            int mid = (l+h)/2;
            int n=0, c=0;

            for(auto &i:bloom) {
                if(i<=mid) c+= 1;
                else c=0;
                if(c==k) n++, c=0;
            }

            if(n>=m) h = mid;
            else l = mid+1;
        }
        return l;
    }
};