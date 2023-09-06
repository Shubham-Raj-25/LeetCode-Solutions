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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }

        temp = head;

        int size = len/k;
        int rem  = len%k;

        vector<ListNode*> ans;
        
        while(k){
            
            ListNode* thead = temp;

            int lim = size;
            if(rem>0)
                lim++;

            for(int i=0;i<lim-1 && temp!=NULL;i++ )
                temp = temp->next;
            
            ListNode* prev = temp;
            if(temp)
                {temp = temp->next;
            prev -> next = NULL;}

            ans.push_back(thead);

            k--;
            rem--;

        }

        return ans;

    }
};