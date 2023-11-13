class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
	    int m = grid[0].size();
	    //int ans = 0;
	    
	    vector<vector<int>> vis(n, vector<int>(m,0));
	    //vector<vector<int>> dist(n ,vector<int>(m,0));
	    queue<pair<int,int>> q; 
	    
	    //so as to not change the original matrix
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
	            vis[i][j] = grid[i][j];
	        }
	    }
	    
	    
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
	            if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1) {
	                q.push({i,j});
	                vis[i][j] = 0;
	            }
	        }
	    }
	    
	    int delrow[] = {-1, 0, +1, 0};
	    int delcol[] = {0, +1, 0, -1};
	    
	    while(!q.empty()) {
	        int row = q.front().first;
	        int col = q.front().second;
	        //int steps = q.front().second;
	        q.pop();
	        
	        //dist[row][col] = steps;
	        
	        for(int i=0; i<4; i++) {
	            int nrow = row + delrow[i];
	            int ncol = col + delcol[i];
	            
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol]==1) {
	                vis[nrow][ncol] = 0;
	                q.push({nrow,ncol});
	            }
	        }
	    }
	    int count = 0;
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
	            if(vis[i][j]==1)
	                count += 1;
	        }
	    }
	    
	    return count;
    }
};