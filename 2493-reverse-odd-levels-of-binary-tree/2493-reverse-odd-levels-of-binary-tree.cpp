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
    TreeNode* reverseOddLevels(TreeNode* root) {
        // bfs with a stack and a queue?
        stack<int> st;
        queue<TreeNode*> q, temp;
        int level = 0;
        q.push(root);

        while(q.size()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left != nullptr){
                    q.push(curr->left);
                    q.push(curr->right);
                }
                
                if(level % 2 != 0){
                    temp.push(curr);
                    st.push(curr->val);
                }
            }

            if(level % 2 != 0){ // reverse the values
                while(temp.size()){
                    TreeNode* curr = temp.front();
                    temp.pop();
                    curr->val = st.top();
                    st.pop();
                }
            }
            level ++;
        }
        
        return root;
    }
};