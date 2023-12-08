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

    void find_ans(TreeNode* root, string &ans) {
        if(root==NULL) {
            return ;
        }

        ans += to_string(root->val);

        if(root->left || root->right) {
            ans += '(';
            find_ans(root->left, ans);
            ans += ')';
        }
        if(root->right) {
            ans += '(';
            find_ans(root->right, ans);
            ans += ')';
        }
    }

    string tree2str(TreeNode* root) {
        string ans = "";

        find_ans(root,ans);
        return ans;
    }
};