class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string a = s, b = s;
        auto pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char x = s[pos];
            for (char &ch : a)
                if (ch == x) ch = '9';
        }
        if (s[0] != '1') {
            char x = s[0];
            for (char &ch : b)
                if (ch == x) ch = '1';
        } else {
            for (size_t i = 1; i < s.size(); ++i) {
                char ch = s[i];
                if (ch != '0' && ch != '1') {
                    char x = ch;
                    for (char &d : b)
                        if (d == x) d = '0';
                    break;
                }
            }
        }
        return stoi(a) - stoi(b);
    }
};