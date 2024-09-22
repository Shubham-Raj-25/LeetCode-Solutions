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
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        unordered_map<Node*, Node*> clone;
        queue<Node*> q;

        clone[node] = new Node(node->val);
        q.push(node);

        while(q.size()){
            Node* curr = q.front();
            q.pop();

            for(Node* nei : curr->neighbors){
                
                if(clone.find(nei) == clone.end()){ // if not visited
                    clone[nei] = new Node(nei->val);
                    q.push(nei);
                }

                clone[curr]->neighbors.push_back(clone[nei]);
            }
        }

        return clone[node];
    }
};