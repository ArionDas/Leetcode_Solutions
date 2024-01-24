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

    int count_odd(vector<int>& numbers) {
        int cnt = 0;

        for(int i=1; i<10; i++) {
            if(numbers[i] & 1) cnt += 1;
        }
        return cnt;
    }

    int find_palin_paths(TreeNode* root, vector<int>& numbers) {
        if(root == NULL)
            return 0;

        numbers[root->val] += 1;

        if(root->left == NULL && root->right == NULL) {
            int count = count_odd(numbers);
            numbers[root->val] -= 1;

            if(count > 1)
                return 0;
            return 1;
        }

        int left = find_palin_paths(root->left, numbers);
        int right = find_palin_paths(root->right, numbers);

        numbers[root->val] -= 1;

        return left + right;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> numbers(10, 0);

        return find_palin_paths(root, numbers);
    }
};