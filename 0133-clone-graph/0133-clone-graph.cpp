/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node,map<Node*, Node*>& og_to_clone,set<Node*>& vis){
        if(node == NULL || vis.count(node))
            return;
        
        vis.insert(node);

        if(og_to_clone.find(node) == og_to_clone.end())
            og_to_clone[node]  = new Node(node->val);
        
        for(auto nei : node->neighbors){
            if(og_to_clone.find(nei) == og_to_clone.end())
                og_to_clone[nei] = new Node(nei->val);
            og_to_clone[node]->neighbors.push_back(og_to_clone[nei]);
            dfs(nei,og_to_clone,vis);
        }
    }

    Node* cloneGraph(Node* node) {
        map<Node*, Node*> og_to_clone;
        set<Node*> vis;
        dfs(node,og_to_clone,vis);
        return og_to_clone[node];
    }
};