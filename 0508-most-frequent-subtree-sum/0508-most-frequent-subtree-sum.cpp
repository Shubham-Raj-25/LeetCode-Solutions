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
    int func(TreeNode* root, unordered_map<int,int>& mp,int maxi){
        if(!root)
            return 0;
        
        int sum = root->val + func(root->left,mp,maxi) + func(root->right,mp,maxi);

        mp[sum]++;

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>mp;
        int maxi = func(root,mp,0);
        maxi = 0;
        vector<int> ans;

        for(auto it:mp) maxi = max(maxi,it.second);
        
        for(auto it:mp)
            if(it.second==maxi)
                ans.push_back(it.first);
        
        return ans;
    }
};