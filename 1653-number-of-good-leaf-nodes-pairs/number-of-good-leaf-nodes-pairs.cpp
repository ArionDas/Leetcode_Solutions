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
    int count = 0;

    vector<int> dfs(TreeNode* node, int distance) {
        vector<int> ds;
        if(node->left == NULL && node->right == NULL) {
            ds.push_back(1);
            return ds;
        }

        vector<int> l,r;

        if(node->left) l = dfs(node->left, distance);
        if(node->right) r = dfs(node->right, distance);

        for(auto x:l) {
            for(auto y:r) {
                if(x+y <= distance) count += 1;
            }
        }

        for(auto x:l) {
            if(x+1 < distance)
                ds.push_back(x+1);
        }

        for(auto y:r) {
            if(y+1 < distance)
                ds.push_back(y+1);
        }

        return ds;
    }

    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return count;
    }
};