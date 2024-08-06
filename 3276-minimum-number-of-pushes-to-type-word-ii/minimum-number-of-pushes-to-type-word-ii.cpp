class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26, 0);
        int len = word.length();

        for(char ch:word) {
            count[ch - 'a']++;
        }

        sort(count.begin(), count.end(), greater<int>());
        int k = 0;
        int num = 1;
        int i = 0;
        int push = 0;

        while(i< 26 && count[i] > 0) {
            if(k!=0 && k%8==0)
                num += 1;
            push += count[i] * num;
            k += 1;
            i += 1;
        }

        return push;
    }
};