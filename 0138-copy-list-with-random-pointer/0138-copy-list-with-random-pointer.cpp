/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node* temp = head;
        Node* prev = NULL;
        
        unordered_map<Node*,Node*> copy2real, real2copy;

        while(temp){
            
            Node* node = new Node(temp->val);

            copy2real[node] = temp;
            real2copy[temp] = node;

            if(prev)
                prev->next = node;

            prev = node;
            temp = temp->next;

        }

        real2copy[NULL] = NULL;
        copy2real[NULL] = NULL;

        prev->next = NULL;

        temp = real2copy[head];

        while(temp){
            temp->random = real2copy[copy2real[temp]->random];
            temp = temp->next;
        }

        return real2copy[head];

    }
};