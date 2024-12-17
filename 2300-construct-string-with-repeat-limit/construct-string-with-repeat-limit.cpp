class Solution {
public:
    string repeatLimitedString(string s, int rl) {
        int n = s.length();
        unordered_map<char,int> um;
        for(auto it:s) {
            um[it]++;
        }

        priority_queue<pair<char,int>> pq;
        for(auto it = um.begin(); it!=um.end(); it++) {
            pq.push(make_pair(it->first, it->second));
        }

        //cout << pq.size() << endl;

        string ans = "";

        while(!pq.empty()) {
            
            if(pq.size() == 1) {

                pair<char,int> p = pq.top();
                pq.pop();

                char ch = p.first;
                int fr = p.second;

                int times = min(fr,rl);
                while(times--) {
                    ans += ch;
                }
                break;
            }

            pair<char,int> p = pq.top();
            pq.pop();

            char ch = p.first;
            int fr = p.second;

            //cout << ch << " " << fr << endl;

            if(fr>rl) {
                int times = rl;
                fr -= rl;
                while(times--) {
                    ans += ch;
                }
                pair<char,int> q = pq.top();
                pq.pop();
                char ch2 = q.first;
                int fr2 = q.second;

                ans += ch2;
                fr2 -= 1;

                //if(fr > 0) {
                    pq.push(make_pair(ch, fr));
                //}
                if(fr2 > 0) {
                    pq.push(make_pair(ch2, fr2));
                }
            }

            else {
                //cout << "2nd" << endl;
                int times = fr;
                while(times--) {
                    ans += ch;
                }
            }

            //cout << ans << endl;
        }

        return ans;
    }
};