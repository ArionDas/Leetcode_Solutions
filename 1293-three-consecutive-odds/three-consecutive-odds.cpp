class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()<3) return 0;

        int len = arr.size();
        for(int i=0; i<len-2; i++) {
            if(arr[i]%2!=0 && arr[i+1]%2!=0 && arr[i+2]%2!=0)
                return 1;
        }
        return 0;
    }
};