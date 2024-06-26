class Solution {
public:
    bool issafe(vector<vector<int>> &dist,int safedis,int row[],int col[]){
        int n=dist.size();
        queue<pair<int,int>> q;
        if(dist[0][0]<safedis) return false;
        q.push({0,0});
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        while(!q.empty()){
            int r=q.front().first,c=q.front().second;
            q.pop();
            if(r==n-1 && c==n-1) return true;
            for(int i=0;i<4;i++){
                int nr=r+row[i],nc=c+col[i];
                if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc] && dist[nr][nc]>=safedis){
                    vis[nr][nc]=1;
                    q.push({nr,nc});         
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<vector<int>> dist(n,vector<int>(n,0));
        int row[]={0,-1,0,1},col[]={-1,0,1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int dis=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                dist[r][c]=dis;
                for(int i=0;i<4;i++){
                    int nr=r+row[i];
                    int nc=c+col[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
            dis++;
        }
        int l=0,h=INT_MAX;
        int ans=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(issafe(dist,m,row,col)){
                ans=m;
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
    }
};