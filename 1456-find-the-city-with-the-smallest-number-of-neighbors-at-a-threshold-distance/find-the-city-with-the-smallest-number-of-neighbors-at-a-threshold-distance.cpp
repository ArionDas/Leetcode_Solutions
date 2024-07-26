class Solution {
public:

    vector<vector<int>> find_matrix(int n, vector<vector<int>>& edges) {

        vector<vector<int>> matrix(n, vector<int>(n,-1));

        for(auto it:edges) {
            matrix[it[0]][it[1]] = it[2];
            matrix[it[1]][it[0]] = it[2];
        }

        return matrix;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        //int n = matrix.size();
	    //int m = matrix[0].size();
	    
        vector<vector<int>> matrix = find_matrix(n, edges);

	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++) {
	            if(matrix[i][j] == -1)
	                matrix[i][j] = 1e9;
	                
	            if(i==j)
	                matrix[i][j] = 0;
	        }
	    }
	    
	    for(int k=0; k<n; k++) {
	        for(int i=0; i<n; i++) {
	            for(int j=0; j<n; j++) {
	                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	    
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++) {
	            if(matrix[i][j] == 1e9)
	                matrix[i][j] = -1;
	        }
	    }

        int ans = 0;
        int min_count = INT_MAX;
        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(matrix[i][j] <= th) {
                    count += 1;
                }
            }
            if(min_count >= count) {
                ans = i;
                min_count = count;
            }
        }

        return ans;
    }
};