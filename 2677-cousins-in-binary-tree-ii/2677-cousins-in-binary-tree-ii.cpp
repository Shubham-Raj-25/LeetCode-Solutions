class Solution {
public:
    void storeLevelSum(TreeNode* root,vector<int>& levelSum, int level=0){
        if(!root) return;
        levelSum[level]+=root->val;
        storeLevelSum(root->left,levelSum,level+1);
        storeLevelSum(root->right,levelSum,level+1);
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
    void modifiedTree(TreeNode*& root,vector<int>& levelSum,int siblingVal=0,int level=0){
        if(!root) return;
        root->val=levelSum[level]-root->val-siblingVal;
        int leftVal=root->left?root->left->val:0;
        modifiedTree(root->left,levelSum,(root->right?root->right->val:0),level+1);
        modifiedTree(root->right,levelSum,leftVal,level+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        int h=depth(root);
        vector<int> levelSum(h,0);
        storeLevelSum(root,levelSum);
        modifiedTree(root,levelSum);
        return root;
    }
};