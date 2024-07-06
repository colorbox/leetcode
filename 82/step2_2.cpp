/*
メソッド切り出しで多少読みやすくしたが、根本的なロジックは変わっていない。
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy_head = ListNode(0, head);
        ListNode* current = &dummy_head;

        while (current) {
            ListNode* group_top = current->next;
            while (group_top && group_top->next && group_top->val == group_top->next->val) {
                group_top  = NextGroupTop(group_top);
            }
            current->next = group_top;
            current = current->next;
        }
        return dummy_head.next;
    }

private:

    ListNode* NextGroupTop(ListNode* head) {
        ListNode* current = head;
        while (current && current->next && current->val == current->next->val) {
            current = current->next;
        }
        return current->next;
    }
};
