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
class FindElements {
private:
    void formTree(TreeNode* root){
        if(root->left){
            root->left->val = 2 * root->val + 1;
            elements.insert(2 * root->val + 1);
            formTree(root->left);
        }
        if(root->right){
            root->right->val = 2 * root->val + 2;
            elements.insert(2 * root->val + 2);
            formTree(root->right);
        }
    }
public:
    unordered_set<int> elements;
    FindElements(TreeNode* root) {
        root->val = 0;
        elements.insert(0);
        if(root->left){
            root->left->val = 1;
            elements.insert(1);
            formTree(root->left);
        }
        if(root->right){
            root->right->val = 2;
            elements.insert(2);
            formTree(root->right);
        }
    }
    
    bool find(int target) {
        return elements.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */