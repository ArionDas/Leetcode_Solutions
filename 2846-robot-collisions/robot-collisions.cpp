class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, pair<int, char>>> sortedROB;
        for (int i = 0; i < positions.size(); i++) {
            sortedROB.push_back({positions[i], {i, directions[i]}});
        }
        sort(sortedROB.begin(), sortedROB.end());

        stack<pair<int, pair<int, char>>> st;

        for (auto ROB : sortedROB) {
            while (!st.empty()) {
                auto top = st.top();
                int topIndex = top.second.first;
                int topHealth = healths[topIndex];

                if (ROB.second.second == 'L' && top.second.second == 'R') { // will collide
                    if (topHealth > healths[ROB.second.first]) {
                        healths[topIndex]--;
                        healths[ROB.second.first] = 0;
                        break;
                    } else if (topHealth < healths[ROB.second.first]) {
                        healths[ROB.second.first]--;
                        healths[topIndex] = 0;
                        st.pop();
                    } else {
                        healths[topIndex] = 0;
                        healths[ROB.second.first] = 0;
                        st.pop();
                        break;
                    }
                } else {
                    st.push(ROB);
                    break;
                }
            }
            if (st.empty()) {
                st.push(ROB);
            }
        }

        vector<int> ans;
        for (int i = 0; i < healths.size(); i++) {
            if (healths[i] != 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};