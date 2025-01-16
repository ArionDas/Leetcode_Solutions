class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if(grid[0][0] != 0)
            return -1;

        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({0, 0});

        int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 1;

        while(!q.empty()) {
            int nx = q.front().first;
            int ny = q.front().second;
            q.pop();

            for(int i=0; i<8; i++) {
                int nnx = nx + dx[i];
                int nny = ny + dy[i];

                if(nnx>=0 && nnx<n && nny>=0 && nny<m && grid[nnx][nny] == 0 && dist[nnx][nny] > dist[nx][ny] + 1) {
                    dist[nnx][nny] = dist[nx][ny] + 1;
                    q.push({nnx, nny});
                }
            }
        }

        return dist[n-1][m-1] == INT_MAX? -1 : dist[n-1][m-1];
    }
};