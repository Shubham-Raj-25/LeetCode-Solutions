class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* move = dummy;

        while (true) {
            int target = -1;
            int mini = INT_MAX;

            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr && lists[i]->val < mini) {
                    mini = lists[i]->val;
                    target = i;
                }
            }

            if (target == -1) break;

            move->next = lists[target];
            move = move->next;

            lists[target] = lists[target]->next;
        }

        return dummy->next;
    }
};
