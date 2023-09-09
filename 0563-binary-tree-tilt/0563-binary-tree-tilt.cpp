class Solution {
public:
    int findSumSubTree(TreeNode* root) {
        if (!root)
            return 0;
        
        int sum = root->val;
        sum += findSumSubTree(root->left) + findSumSubTree(root->right);

        return sum;
    }

    int findTilt(TreeNode* root) {
        if (!root)
            return 0;
        
        int sum = abs(findSumSubTree(root->left) - findSumSubTree(root->right));
        sum += findTilt(root->left) + findTilt(root->right);
    
        return sum;
    }
};
