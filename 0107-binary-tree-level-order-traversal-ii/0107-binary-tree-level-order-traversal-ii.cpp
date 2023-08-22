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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> st;
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                TreeNode* front = q.front();
                q.pop();
                temp.push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
            }
            st.push(temp);
        }

        while(!st.empty()){
            auto abc = st.top();
            st.pop();
            ans.push_back(abc);
        }
        return ans;
    }
};