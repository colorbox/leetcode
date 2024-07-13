class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy_head = ListNode(-1, head);
        ListNode* current = &dummy_head;
        while (current) {
            ListNode* group_top = current->next;
            while (group_top && group_top->next && group_top->val == group_top->next->val) {
                int group_val  =group_top->val;
                while (group_top && group_top->val == group_val) {
                    group_top = group_top->next;
                }
            }
            current->next = group_top;
            current = current->next;
        }
        return dummy_head.next;
    }
};
