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
    void dfs(TreeNode* lft, TreeNode* rt, int level){
        if(lft == nullptr){
            return;
        }

        if(level % 2 != 0){ // odd level so swap values
            swap(lft->val,rt->val);
        }

        dfs(lft->left,rt->right,level+1);
        dfs(lft->right,rt->left,level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left,root->right,1);
        return root;
    }
};