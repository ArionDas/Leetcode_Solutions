class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> words(wordList.begin(), wordList.end());
        q.push({beginWord, 1});

        words.erase(beginWord);

        while(!q.empty()) {
            pair<string,int> top = q.front();
            q.pop();
            string str = top.first;
            int steps = top.second;

            if(str == endWord)
                return steps;

            for(int i=0; i<str.length(); i++) {
                char original = str[i];

                for(char ch = 'a'; ch <= 'z'; ch++) {
                    str[i] = ch;
                    if(words.find(str) != words.end()) {
                        words.erase({str});
                        q.push({str, steps+1});
                    }
                }

                str[i] = original;
            }
        }
        return 0;
    }
};