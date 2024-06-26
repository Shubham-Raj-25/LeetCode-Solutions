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
    void dfs(TreeNode* root,vector<int>& values){
        if(!root)
            return;
        dfs(root->left,values);
        values.push_back(root->val);
        dfs(root->right,values);
    }

    TreeNode* convert(int s, int e, vector<int>& values){
        if(s > e)
            return NULL;
        
        int mid = (s+e)/2;

        TreeNode* root = new TreeNode(values[mid]);

        root->left = convert(s,mid-1,values);
        root->right= convert(mid+1,e,values);

        return root;
    }
   
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        dfs(root,values);
        return convert(0,values.size()-1,values);
    }
};