class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> frnds(n,0);

        for(int i=0; i<n; i++)
            frnds[i] = i+1;

        int start = 0;
        // int ans;
        // bool flag = 1;
        // int j=0;
        // while(flag) {
        //     j=0;
        //     //int i=0;
        //     while(j<k) {
        //         if(frnds[start]!=-1) {
        //             j = j+1;
        //         }
        //         start = (start+1)%n;
        //     }
        //     //ans = frnds[j];
        //     frnds[j] = -1;
        //     start = j;

        //     int count = 0;
        //     for(int i=0; i<n; i++) {
        //         if(frnds[i]!=-1) {
        //             count += 1;
        //             ans = frnds[i];
        //         }
        //     }
        //     cout << count << endl;
        //     if(count<2)
        //         flag = 0;
        // }

        while(n>1) {
            start = (start + (k-1))%n;
            frnds.erase(frnds.begin() + start);
            n -= 1;
        }

        return frnds[0];
    }
};