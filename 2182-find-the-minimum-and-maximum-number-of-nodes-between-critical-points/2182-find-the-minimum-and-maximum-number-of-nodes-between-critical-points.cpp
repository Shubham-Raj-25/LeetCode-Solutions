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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> data;
        ListNode* temp = head->next;
        int prev = head ->val;
        int idx = 1;

        while(temp->next){
            int curr = temp -> val;
            int next = temp -> next -> val;
            if((curr>prev && curr>next) || (curr<prev && curr<next))
                data.push_back(idx);
            idx++;
            prev = curr;
            temp = temp->next;
        }
        int n = data.size();

        if(n < 2)
            return {-1,-1};
        
        int mini = INT_MAX;

        for(int i=0;i<n-1;i++)
            mini = min(data[i+1]-data[i],mini);
        
        return {mini,data[n-1]-data[0]};

    }
};