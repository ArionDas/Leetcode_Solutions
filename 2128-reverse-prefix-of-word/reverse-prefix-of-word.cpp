class Solution {
public:

    string reverseprefix(string word, int j) {
        int i=0;
        while(i<=j) {
            char c = word[i];
            word[i] = word[j];
            word[j] = c;
            i++;
            j--;
        }
        return word;
    }

    string reversePrefix(string word, char ch) {
        for(int i=0; i<word.length(); i++) {
            if(word[i]==ch)
                return reverseprefix(word,i);
        }
        return word;
    }
};