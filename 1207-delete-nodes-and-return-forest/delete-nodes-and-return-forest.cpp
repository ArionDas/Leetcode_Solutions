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
    vector<TreeNode*> res;
    unordered_map<int,int> um;

    void delete_nodes(TreeNode* &root) {
        if(root) {
            delete_nodes(root->left);
            delete_nodes(root->right);

            if(um.find(root->val) != um.end()) {
                if(root->left) res.push_back(root->left);
                if(root->right) res.push_back(root->right);

                root = NULL;
            }
        }
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i:to_delete)
            um[i]++;

        delete_nodes(root);
        if(root)
            res.push_back(root);
        return res;
    }
};