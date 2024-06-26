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
    void dfs(TreeNode* root, int& sum){
        if(!root)
            return;
        dfs(root->right,sum);
        root->val += sum;
        sum = root->val;
        dfs(root->left,sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        // R -> N -> L
        TreeNode* dummy = root;
        int sum = 0;
        dfs(dummy,sum);
        return root;
    }
};