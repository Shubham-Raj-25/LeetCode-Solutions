class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smallerHead = new ListNode(0); // dummy node for smaller list
        ListNode* smallerTail = smallerHead;
        ListNode* biggerHead = new ListNode(0); // dummy node for bigger list
        ListNode* biggerTail = biggerHead;
        
        while(head != NULL){
            if(head->val < x){
                smallerTail->next = head;
                smallerTail = smallerTail->next;
            }
            else{
                biggerTail->next = head;
                biggerTail = biggerTail->next;
            }
            head = head->next;
        }
        
        smallerTail->next = biggerHead->next; // merge smaller and bigger lists
        biggerTail->next = NULL; // set the end of the bigger list to NULL
        
        ListNode* newHead = smallerHead->next; // new head of the partitioned list
        delete smallerHead; // free memory allocated for the dummy node
        
        return newHead;
    }
};
