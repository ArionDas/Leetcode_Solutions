class Solution {
public:

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for(int i=1; i<=9; i++) {
            int num = i;
            int nd = i + 1;

            while(num<=high && nd <= 9) {
                num = num*10 + nd;
                if(low <= num && num <= high)
                    ans.push_back(num);
                    nd++;
            }
        } 

        sort(ans.begin(), ans.end());
        return ans;
    }
};