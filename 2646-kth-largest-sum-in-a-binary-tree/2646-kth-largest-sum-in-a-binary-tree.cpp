/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> data;
        queue<TreeNode*> q;
        q.push(root);

        while (q.size()) {
            int size = q.size();
            long long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            data.push_back(sum);
        }

        if (data.size() < k)
            return -1;
        sort(data.rbegin(), data.rend());
        return data[k-1];
    }
};