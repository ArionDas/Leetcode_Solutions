class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int one=0, flip=0;

        for(auto it:s) {
            if(it=='1') {
                one += 1;
            }
            else {
                flip += 1;
            }
            flip = min(flip, one);
        }

        return flip;
    }
};