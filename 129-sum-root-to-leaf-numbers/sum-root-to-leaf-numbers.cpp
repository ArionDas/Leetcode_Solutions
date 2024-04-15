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

    void find_sum(TreeNode* root, int num, int &ans) {

        if(!root)
            return;

        num = num*10 + root->val;

        if(!root->left && !root->right)
            ans += num;

        find_sum(root->left, num, ans);
        find_sum(root->right, num, ans);
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int num = 0;

        find_sum(root, num, ans);

        return ans;
    }
};