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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // O(N) space and O(N) time
        map<int,TreeNode*> mp;
        unordered_set<int> has_parent;
        for(auto it : descriptions){
            if(mp.find(it[0]) == mp.end()){
                TreeNode* par = new TreeNode(it[0]);
                mp[it[0]] = par;
            }
            if(mp.find(it[1]) == mp.end()){
                TreeNode* child = new TreeNode(it[1]);
                mp[it[1]] = child;
            }
            if(it[2])
                mp[it[0]] -> left = mp[it[1]];
            else
                mp[it[0]] -> right = mp[it[1]];
            has_parent.insert(it[1]);
        }

        for(auto it: descriptions)
            if(!has_parent.count(it[0]))
                return mp[it[0]];
            
        return NULL;
    }
};