// Brute - Just Check Bigger Number from last
class Solution {
public:
    int maximumSwap(int num) {
        // max num = 1,0000,0000 = 1e8
        // max string length = 9

        // convert num to string
        string s = to_string(num);
        
        for(int i=0;i<s.size();i++){
            int ind = i;
            
            // find max possible number to swap with
            for(int j=s.size()-1;j>i;j--){
                if(s[ind]<s[j]){
                    ind = j;
                }
            }

            // if ind get changed
            if(ind != i and s[i]<s[ind]){
                swap(s[i],s[ind]);
                // only one swap allowed
                // convert string to number
                return stoi(s);
            }
        }

        return num;
    }
};