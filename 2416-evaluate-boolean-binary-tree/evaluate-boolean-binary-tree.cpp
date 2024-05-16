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

    bool answer(TreeNode* root) {
        if(!(root->right && root->left))
            return root->val;

        bool left = answer(root->left);
        bool right = answer(root->right);

        if(root->val==2) {
            return (left|right);
        }
        else {
            return (left&right);
        }
        return 1;
    }

    bool evaluateTree(TreeNode* root) {
        return answer(root);
    }
};