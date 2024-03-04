class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int pow) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int i=0, j=n-1;
        int score=0;
        int ans=0;
        while(i<=j) {
            if(pow>=tokens[i]) {
                pow -= tokens[i];
                score += 1;
                ans = max(ans, score);
                i += 1;
            }
            else if(score>0) {
                pow += tokens[j];
                j -= 1;
                score -= 1;
            }
            else {
                break;
            }
        }
        return ans;
    }
};