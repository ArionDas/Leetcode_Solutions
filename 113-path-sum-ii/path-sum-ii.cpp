/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* root, int curr_sum, int sum, vector<vector<int>> &res, vector<int> &ds) {
        if(!root)
            return;
            
        curr_sum += root->val;
        ds.push_back(root->val);
        
        if(curr_sum==sum && root->left==NULL && root->right==NULL)
            res.push_back(ds);
            
        solve(root->left, curr_sum, sum, res, ds);
        solve(root->right, curr_sum, sum, res, ds);
        
        curr_sum -= root->val;
        ds.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> ds;
        solve(root, 0, sum, res, ds);
        return res;
    }
};