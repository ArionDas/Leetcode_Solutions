class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int gs) {
        map<int,int> mp;
        int n = hand.size();

        if(n%gs != 0)
            return 0;

        for(int i:hand)
            mp[i]++;

        while(mp.size()>0) {
            int p = mp.begin()->first;

            for(int i=0; i<gs; i++) {
                if(mp.find(p+i)!=mp.end() && mp[p+i] > 0) {
                    mp[p+i]--;
                    if(mp[p+i]==0) {
                        mp.erase(p+i);
                    }
                }
                else {
                    return 0;
                }
            }
        }
        return 1;
    }
};