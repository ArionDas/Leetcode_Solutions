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

    void find_leaf_track(TreeNode* root, vector<int> &t) {
        if(root==NULL)
            return;

        find_leaf_track(root->left, t);
        if(root->left==NULL && root->right==NULL)
            t.push_back(root->val);
        find_leaf_track(root->right, t);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2;

        find_leaf_track(root1,t1);
        find_leaf_track(root2,t2);

        if(t1.size()==t2.size()) {
            for(int i=0; i<t1.size(); i++) {
                if(t1[i]!=t2[i])
                    return 0;
            }
            return 1;
        }
        else
            return 0;

        return 1;
    }
};