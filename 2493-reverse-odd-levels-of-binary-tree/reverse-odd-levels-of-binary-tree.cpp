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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int lvl = 0;
        vector<vector<TreeNode*>> tree;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int qs = q.size();
            
            vector<TreeNode*> level;
            
            while(qs--) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node);

                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }

            if(lvl&1) {
                reverse(level.begin(), level.end());
            }
            lvl += 1;
            tree.push_back(level);
        }

        int n = tree.size();
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<tree[i].size(); j++) {
                tree[i][j]->left = tree[i+1][2*j];
                tree[i][j]->right = tree[i+1][2*j+1];
            }
        }

        return tree[0][0];
    }
};