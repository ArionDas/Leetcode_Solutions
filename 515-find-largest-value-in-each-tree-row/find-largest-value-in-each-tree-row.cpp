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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        if(!root)
            return {};

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int s = q.size();
            vector<int> temp;
            while(s--) {
                TreeNode* node = q.front();
                q.pop();
                //if(!node) continue;
                temp.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(*max_element(temp.begin(), temp.end()));
        }

        return ans;
    }
};