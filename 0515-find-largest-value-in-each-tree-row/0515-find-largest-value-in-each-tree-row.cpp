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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            int sz = q.size();
            int maxi = INT_MIN;
            for(int i=0;i<sz;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr == nullptr){
                    return ans;
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                maxi = max(maxi, curr->val);
            }
            ans.push_back(maxi);
        }

        return ans;
    }
};