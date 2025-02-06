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
    pair<int,int> dfs(TreeNode* root, vector<int>& sizes){ // returns {depth,size}
        if(!root){
            return {0,0};
        }

        auto [leftDepth,leftSize] = dfs(root->left,sizes);
        auto [rightDepth,rightSize] = dfs(root->right,sizes);

        if (leftDepth != rightDepth || leftDepth == -1 || rightDepth == -1) {
            return {-1,-1};
        }

        // there is a valid perfect binary tree
        sizes.push_back(leftSize+rightSize+1);
        return {leftDepth+1,leftSize+rightSize+1};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sizes;
        dfs(root,sizes);
        if(sizes.size() < k){
            return -1;
        }
        sort(sizes.begin(),sizes.end());
        return sizes[sizes.size()-k];
    }
};

/*
size of the kth largest perfect binary

A perfect binary tree is a tree where all leaves are on the same level,
and every parent has two children.

leaf nodes are pbt
if for a tree leftSubtree's depth == rightSubstree's depth -> pbt

d = 1, s = 1
d = 2, s = 3
d = 3, s = 7 
d = 4, s = 15
once a non pbt always a non pbt

*/ 