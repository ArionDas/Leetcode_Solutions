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

    void find_inorder(TreeNode* root, vector<int> &inorder) {
        if(root == NULL)
            return;

        find_inorder(root->left, inorder);
        inorder.push_back(root->val);
        find_inorder(root->right, inorder);
        return;
    }

    TreeNode* inordertobst(int s, int e, vector<int> inorder) {
        if(s>e)
            return NULL;

        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(inorder[mid]);

        root->left = inordertobst(s,mid-1,inorder);
        root->right = inordertobst(mid+1,e,inorder);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        find_inorder(root, inorder);

        return inordertobst(0, inorder.size()-1, inorder);
    }
};