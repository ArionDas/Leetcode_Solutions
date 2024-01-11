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
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
            return 0;

        int minval = root->val;
        int maxval = root->val;

        differ(root, minval, maxval);
        return diff;
    }
private:
    int diff = 0;
    void differ(TreeNode* root, int minval, int maxval) {
        if(!root)
            return;

        diff = max(diff, max(abs(minval-root->val), abs(maxval-root->val)));
        minval = min(minval, root->val);
        maxval = max(maxval, root->val);
        differ(root->left, minval, maxval);
        differ(root->right, minval, maxval);
    }
};