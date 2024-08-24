#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_map;
        buildParentMap(root, nullptr, parent_map);
        
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        
        int current_distance = 0;
        
        while (!q.empty()) {
            if (current_distance == k) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parent_map[node] && !visited.count(parent_map[node])) {
                    q.push(parent_map[node]);
                    visited.insert(parent_map[node]);
                }
            }
            ++current_distance;
        }
        
        return {};
    }
    
private:
    void buildParentMap(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parent_map) {
        if (!node) return;
        parent_map[node] = parent;
        buildParentMap(node->left, node, parent_map);
        buildParentMap(node->right, node, parent_map);
    }
};