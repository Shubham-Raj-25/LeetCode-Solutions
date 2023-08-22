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
    void dfs(int currSum, TreeNode* node, int targetSum, vector<int>& temp, vector<vector<int>>& ans){
        
        if(!node->left && !node->right){
            if(currSum==targetSum)
                ans.push_back(temp);
            return;
        }

        if(node->left){
            temp.push_back(node->left->val);
            dfs(currSum+node->left->val,node->left,targetSum,temp,ans);
            temp.pop_back();
        }

        if(node->right){
            temp.push_back(node->right->val);
            dfs(currSum+node->right->val,node->right,targetSum,temp,ans);
            temp.pop_back();
        }

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(!root)
            return ans;
        temp.push_back(root->val);
        dfs(root->val,root,targetSum,temp,ans);
        return ans;
    }
};