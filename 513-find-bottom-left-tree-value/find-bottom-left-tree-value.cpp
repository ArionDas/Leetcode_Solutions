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
    int findBottomLeftValue(TreeNode* root) {
        vector<int> temp;
        if(root->left == NULL && root->right == NULL)
            return root->val;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            temp.clear();
            for(int i=0; i<size; i++) {
                TreeNode* temp_node = q.front();
                q.pop();

                temp.push_back(temp_node->val);

                if(temp_node->left) q.push(temp_node->left);
                if(temp_node->right) q.push(temp_node->right);
            }
        }

        return temp[0];
    }
};