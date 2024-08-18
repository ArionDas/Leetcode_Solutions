class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)
            return 1;

        set<long> pq;
        pq.insert(1);
        long num = 1;
        for(int i=0; i<n; i++) {
            num = *pq.begin();
            pq.erase(num);
            pq.insert(num*2);
            pq.insert(num*3);
            pq.insert(num*5);

            cout << num << endl;
        }

        return num;
    }
};