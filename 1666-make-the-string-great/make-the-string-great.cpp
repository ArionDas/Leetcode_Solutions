class Solution {
public:
    bool sameCharOppositeCase(char a, char b){
        if(a>='a' && b>='a')return false;
        if(a<'a' && b<'a')return false;
        if((a-'A' == b-'a') || (a-'a' == b-'A'))return true;
        return false;
    }
    string makeGood(string s) {
        int i=0;
        while(i+1<s.size()){
            if(sameCharOppositeCase(s[i], s[i+1])){
                s=s.erase(i,2);
                i--;
                if(i<0)i=0;
            }else
                i++;
        }
        return s;
    }
};