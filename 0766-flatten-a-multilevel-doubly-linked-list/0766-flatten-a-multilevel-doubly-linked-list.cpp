/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        // O(1) SPACE SOLUTION
        for(Node* h = head; h; h = h->next){
            if(h->child){
                Node* nxt = h->next;
                h->next = h->child;
                h->next->prev = h;
                h->child = NULL;
                Node* temp = h->next;
                while(temp->next)
                    temp = temp->next;
                temp -> next = nxt;
                if(nxt)
                    nxt ->prev = temp;
            }
        }

        return head;
    }
};