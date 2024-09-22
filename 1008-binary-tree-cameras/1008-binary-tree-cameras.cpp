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
    int ans = 0;
    int minCameraCover(TreeNode* root) {
        int root_state = dfs(root);
        // 0 -> not covered by camera
        // 1 -> covered by surrounding camera
        // 2 -> have camera on it
        if(root_state == 0)
            return ans+1;
        return ans;
    }
    int dfs(TreeNode* root){
        if(root == NULL)
            return 1;
        
        int left_child_state = dfs(root->left);
        int right_child_state = dfs(root->right);
        
        if(left_child_state == 0 || right_child_state == 0){
            ans++;
            return 2;
        }
        else if(left_child_state == 2 || right_child_state == 2)
            return 1; 
        else
            return 0;
    }
};