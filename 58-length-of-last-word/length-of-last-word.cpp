class Solution {
public:
    int lengthOfLastWord(string s) {
        s = s + ' ';
        int len = s.length();

        string wrd = "";
        string word = "";
        for(int i=0; i<len; i++) {
            if(s[i]==' ') {
                if(word.length()!=0)
                    wrd = word;
                word = "";
            }
            else
                word = word + s[i];
        }
        return wrd.length();
    }
};