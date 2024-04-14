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

    void sum_left(TreeNode* root, bool flag, vector<int> &ans) {
        if(root == NULL)
            return ;

        if(flag && !root->left && !root->right) {
            ans.push_back(root->val); 
        }

        sum_left(root->left, 1, ans);
        sum_left(root->right, 0, ans);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        vector<int> ans;
        sum_left(root, 0, ans);

        return accumulate(ans.begin(), ans.end(), 0);
    }
};