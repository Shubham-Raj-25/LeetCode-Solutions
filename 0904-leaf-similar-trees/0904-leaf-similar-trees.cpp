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
    void func(TreeNode* root, vector<int>& temp){
        if(!root->left && !root->right){
            temp.push_back(root->val);
            return;
        }

        if(root->left)
            func(root->left,temp);
        if(root->right)
            func(root->right,temp);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1,l2;
        func(root1,l1);
        func(root2,l2);
        return l1==l2;
    }
};