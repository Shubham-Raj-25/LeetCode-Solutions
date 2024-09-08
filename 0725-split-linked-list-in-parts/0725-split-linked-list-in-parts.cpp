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
        ListNode* dummy = head;
        int len = 0;
        vector<ListNode*> ans;

        while(dummy){
            len++;
            dummy = dummy->next;
        }
        
        dummy = head;

        int value = len/k;
        int rem = len%k;
        
        while(dummy){
            ans.push_back(dummy);
            int dist = value + (rem > 0);
            for(int i=0;i<dist-1;i++)
                dummy = dummy->next;
            ListNode* temp = dummy;
            dummy = dummy->next;
            temp->next = NULL;
            rem--;
        }

        while(ans.size() < k)
            ans.push_back(NULL);
        
        return ans;
    }
};