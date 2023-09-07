class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // naieve way, O(n) space and two passes
        if(!head)
            return head;
        vector<int> data;
        ListNode* temp = head;
        while(temp){
            data.push_back(temp->val);
            temp = temp->next;
        }
        reverse(data.begin()+left-1,data.begin()+right);
        temp = head;
        int idx = 0;
        while(temp){
            if(idx>=left-1 && idx<=right-1)
                temp->val = data[idx];
            temp=temp->next;
            idx++;
        }

        return head;
    }
};