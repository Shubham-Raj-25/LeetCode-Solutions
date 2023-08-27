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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> ans;
        if(!root)
            return ans;
        q.push(root);

        while(!q.empty()){
            vector<int> temp;
            int size = q.size();
            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();
                if(node)
                {temp.push_back(node->val);
                for(auto it:node->children)
                    q.push(it);}
            }

            ans.push_back(temp);
        }

        return ans;
    }
};