/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int sum = 0;
        while(head){
            if(head->val){
                sum += head->val;
            }else{
                ListNode* newNode = new ListNode(sum);
                temp -> next = newNode;
                temp = newNode;
                sum = 0;
            }
            head = head->next;
        }

        return dummy->next->next;
    }
};