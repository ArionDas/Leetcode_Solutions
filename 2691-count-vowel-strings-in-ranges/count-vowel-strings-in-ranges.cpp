class Solution {
public:

    bool isVowel(char ch) {
        return (ch=='a' || ch=='i' || ch=='o' || ch=='e' || ch=='u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> word_count(n, 0);

        for(int i=0; i<n; i++) {
            int len = words[i].length();

            if(isVowel(words[i][0]) && isVowel(words[i][len-1])) {
                if(i==0) {
                    word_count[i] = 1;
                }
                else {
                    word_count[i] = word_count[i-1] + 1;
                }
            }
            else {
                if(i!=0)
                    word_count[i] = word_count[i-1];
            }
            //cout << word_count[i] << " ";
        }

        vector<int> ans;
        for(int q=0; q<queries.size(); q++) {
            int l = queries[q][0];
            int r = queries[q][1];
            if(l==0) ans.push_back(word_count[r]);
            else ans.push_back(word_count[r] - word_count[l-1]);
        }

        return ans;
    }
};