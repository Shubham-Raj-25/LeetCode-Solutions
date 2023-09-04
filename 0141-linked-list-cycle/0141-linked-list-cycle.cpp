/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *f = head, *s = head;

        while(f && s){
            if(f->next)
                f = f->next->next;
            else
                return false;
            s=s->next;
            if(f==s) return true;
        }

        return false;
    }
};