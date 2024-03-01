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

    int minSwaps(vector<int> nums, int n) 
{ 
    int len = n; 
    unordered_map<int, int> um; 
    for (int i = 0; i < len; i++) 
        um[nums[i]] = i; 
  
    sort(nums.begin(),nums.end()); 
  
    // To keep track of visited elements. Initialize 
    // all elements as not visited or false. 
    vector<bool> visited(len, false); 
  
    // Initialize result 
    int ans = 0; 
    for (int i = 0; i < len; i++) { 
  
        // already swapped and corrected or 
        // already present at correct pos 
        if (visited[i] || um[nums[i]] == i) 
            continue; 
  
        int j = i, cycle_size = 0; 
        while (!visited[j]) { 
            visited[j] = true; 
  
            // move to next node 
            j = um[nums[j]]; 
            cycle_size++; 
        } 
  
        // Update answer by adding current cycle. 
        if (cycle_size > 0) { 
            ans += (cycle_size - 1); 
        } 
    } 
    return ans; 
}

    int minimumOperations(TreeNode* root) {
        int ans=0;
        vector<int> temp2;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if(temp==NULL) { 
                // prev level is completed
                ans += minSwaps(temp2, temp2.size());
                temp2.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            else {
                temp2.push_back(temp->val);
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
        }
        return ans;
    }
};