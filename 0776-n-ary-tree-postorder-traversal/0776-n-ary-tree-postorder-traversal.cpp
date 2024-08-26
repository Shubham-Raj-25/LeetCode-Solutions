/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void func(Node* curr, vector<int>& ans){
        if(!curr)
            return;
        
        for(auto child : curr->children)
            func(child,ans);
            
        ans.push_back(curr->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        func(root,ans);
        return ans;
    }
};