class Solution {
public:
    int passThePillow(int n, int time) {
        int person = 1;
        bool up = 1;

        while(time) {
            if(up) {
                if(person < n) {
                    person += 1;
                }
                else {
                    up = 0;
                    person -= 1;
                }
            }
            else {
                if(person > 1) {
                    person -= 1;
                }
                else {
                    up = 1;
                    person += 1;
                }
            }
            time -= 1;
        }

        return person;
    }
};