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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> to_remove;
        for(int num: nums) to_remove.insert(num);
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *curr = head;
        while(curr){
            if(to_remove.count(curr -> val))
                prev -> next = curr->next;
            else
                prev = prev->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};