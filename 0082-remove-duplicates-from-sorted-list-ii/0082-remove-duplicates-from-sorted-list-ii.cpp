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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> mp;
        ListNode* temp = head;
        while(temp)
        {
            mp[temp->val]++;
            temp = temp->next;
        }

        vector<int> data;

        for(auto it:mp)
            if(it.second==1)
                data.push_back(it.first);
        
        if(!data.size()) return NULL;

        ListNode* newHead = new ListNode(data[0]);
        temp = newHead;

        for(int i=1;i<data.size();i++){
            ListNode* newNode = new ListNode(data[i]);
            temp->next = newNode;
            temp = newNode;
        }

        return newHead;
    }
};