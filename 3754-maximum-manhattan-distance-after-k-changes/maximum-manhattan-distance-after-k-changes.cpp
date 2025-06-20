class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();
        int x=0, y=0;
        vector<int> dist;

        for (char move : s) {
            if (move == 'N') y += 1;
            else if (move == 'S') y -= 1;
            else if (move == 'E') x += 1;
            else if (move == 'W') x -= 1;
            dist.push_back(abs(x) + abs(y));
        }

        if (k == 0) {
            return *max_element(dist.begin(), dist.end());
        }

        int maxDist = dist[1];
        int prev = dist[0];
        int addedBoost = 0;

        for (int i = 1; i < dist.size(); ++i) {
            if (dist[i] < prev && k > 0) {
                addedBoost += 2;
                k--;
            }
            prev = dist[i];
            dist[i] += addedBoost;
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist;

    }
};