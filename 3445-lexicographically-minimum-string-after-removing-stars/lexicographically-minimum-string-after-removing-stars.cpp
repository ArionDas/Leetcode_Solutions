class Solution {
public:
    string clearStars(string s) {
        int n = s.length();

        auto compare = [](const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(compare)> pq(compare);
        stack<int> st;

        string ans = "";

        for(int i=0; i<n; i++) {
            if(s[i] == '*') {
                pair<char, int> p = pq.top();
                pq.pop();

                char ch = p.first;
                int ind = p.second;

                s[ind] = '.';
                s[i] = '.';
            }
            else {
                pq.push({s[i], i});
            }
        }

        for(auto it:s) {
            if(it!='.')
                ans += it;
        }

        return ans;
    }
};