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
    void dfs(Node* head, vector<int>& data){
        if(!head)
            return ;
        
        data.push_back(head->val);

        if(head->child)
            dfs(head->child,data);
        if(head->next)
            dfs(head->next,data);
    }

    Node* flatten(Node* head) {
        if(!head)
            return head;
        vector<int> data;
        dfs(head,data);

        Node* temp = new Node(data[0]);
        Node* temp2 = temp;
        temp -> child = NULL;
        temp -> prev = NULL;

        for(int i=1;i<data.size();i++){
            Node* New = new Node(data[i]);
            temp -> next = New;
            New -> child = NULL;
            New -> prev = temp;
            New -> next = NULL;
            temp = New;
        }

        return temp2;
    }
};