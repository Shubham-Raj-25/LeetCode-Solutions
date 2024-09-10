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
    int gcd(int a, int b){
        int ans = 1;
        for(int i=2;i<=a;i++)
            if(a % i == 0 && b % i == 0)
                ans = i;
        return ans;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr){
            ListNode* temp = new ListNode(gcd(prev->val,curr->val),curr);
            prev->next = temp;
            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};