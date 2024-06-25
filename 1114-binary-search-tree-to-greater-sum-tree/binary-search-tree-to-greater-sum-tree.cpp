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

    void find_total_sum(TreeNode* root, int &total_sum) {
        if(root==NULL)
            return;

        find_total_sum(root->left, total_sum);
        total_sum += root->val;
        find_total_sum(root->right, total_sum);
    }

    void find_new_tree(TreeNode* root, int &curr_sum, int &total_sum) {
        if(root==NULL)
            return;
        
        find_new_tree(root->left, curr_sum, total_sum);
        int temp = root->val;
        root->val = total_sum - curr_sum;
        curr_sum += temp;
        find_new_tree(root->right, curr_sum, total_sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int total_sum = 0;
        find_total_sum(root, total_sum);
        //cout << total_sum << endl;
        int curr_sum = 0;
        find_new_tree(root, curr_sum, total_sum);

        return root;
    }
};