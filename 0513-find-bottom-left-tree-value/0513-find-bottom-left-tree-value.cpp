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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while(1){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
            
            if(q.size()==0)
                return temp->val;
        }

        return -1;
    }
};