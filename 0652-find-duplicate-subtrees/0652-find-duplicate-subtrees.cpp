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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,vector<TreeNode*>> mp;
        vector<TreeNode*> ans;
        stringify(root,mp);
        for(auto it:mp)
            if(it.second.size()>1)
                ans.push_back(it.second[0]);
        
        return ans;
    }

    string stringify(TreeNode* node,map<string,vector<TreeNode*>>& mp ){
        if(!node)
            return "";
        
        string temp = "[" + stringify(node->left,mp)+to_string(node->val)+stringify(node->right,mp)+"]";

        mp[temp].push_back(node);

        return temp;
    }
};