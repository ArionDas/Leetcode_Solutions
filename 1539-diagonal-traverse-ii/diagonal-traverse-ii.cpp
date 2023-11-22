class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        //vector<int> ans;

        int n = nums.size();
        int m = 0;

        //storing max value in m
        for(int i=0; i<n; i++) {
            if(m<nums[i].size())
                m = nums[i].size();
        }

        vector<vector<int>> temp(m+n);
        vector<int> ans;

        // converting matrix into adjacency list and keeping value in temp
        for(int i=0; i<n; i++) {
            for(int j=0; j<nums[i].size(); j++) {
                temp[i+j].push_back(nums[i][j]);
            }
        }

        //we reverse the matrix
        for(int i=0; i<m+n; i++)
            reverse(temp[i].begin(),temp[i].end());

        for(int i=0; i<m+n; i++) {
            for(int j=0; j<temp[i].size(); j++)
                ans.push_back(temp[i][j]);
        }
        return ans;
    }
};