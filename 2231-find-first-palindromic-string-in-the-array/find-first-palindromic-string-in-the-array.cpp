class Solution {
public:

    bool palindrome(string str) {
        int i=0; 
        int j=str.length()-1;

        while(i<=j) {
            if(str[i]!=str[j])
                return 0;

            i++;
            j--;
        }
        return 1;
    }

    string firstPalindrome(vector<string>& words) {
        for(int i=0; i<words.size(); i++) {
            if(palindrome(words[i])) return words[i];
        }
        return "";
    }
};