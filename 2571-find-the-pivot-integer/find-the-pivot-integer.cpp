class Solution {
public:
    int pivotInteger(int n) {
        if(n==1)
            return n;

        int sum = n*(n+1)/2;
        int req = sum/2;
        int i=sum,j=0;
        int k = n;
        int l = n;
        while(i>=0 && j>=0) {
            j += l;
            if(i==j) {
                //cout << i << " " << j << endl;
                return k;
            }
            i -= k;
            k -= 1;
            l -= 1;
            //else {
                
                
                
                //j += l;
            //}
            //cout << i << " " << j << endl;
        }
        return -1;
    }
};