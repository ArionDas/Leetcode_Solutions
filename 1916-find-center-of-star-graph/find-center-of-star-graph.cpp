class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> um;

        int len = edges.size();

        for(int i=0; i<len; i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            if(um.find(a)!=um.end())
                return a;
            if(um.find(b)!=um.end())
                return b;

            um[a] += 1;
            um[b] += 1;
        }

        return 0;
    }
};