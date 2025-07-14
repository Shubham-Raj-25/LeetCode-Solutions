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
    int getDecimalValue(ListNode* head) {
        
        vector<int> num;
        int integer = 0;
        int i = 0;
        
        while(head)
        {
            num.push_back(head->val);
            head = head ->next;
        }
        
        while(num.size() !=0)
        {
            integer += num.back() * pow(2,i);
            num.pop_back();
            i++;
        }
            return integer;
    }
};