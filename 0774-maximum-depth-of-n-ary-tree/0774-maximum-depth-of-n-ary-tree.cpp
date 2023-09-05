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
    int dfs(Node* root, int ans){
        if(!root)
            return ans;
        int val = ans;
        for(auto it: root->children)
            val = max(val,dfs(it,ans+1));

        return val;            
    }

    int maxDepth(Node* root) {
        int ans = 0;
        if(!root)
            return ans;
        return dfs(root,ans)+1;
    }
};