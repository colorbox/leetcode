/*
new演算子を使用せず、deleteを不要にした。
nextを何度も書くのに違和感があったのでgroup_top変数にした。
チェック済みの最後尾を指すcurrentと、チェック中/同一数値の先頭を指すのgroup_topと役割を分けてわかりやすくした

*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy_head = ListNode(0, head);
        ListNode* current = &dummy_head;

        while (current) {
            ListNode* group_top = current->next;
            while (group_top && group_top->next && group_top->val == group_top->next->val) {
                int group_val = group_top->val;
                while (group_top && group_top->val == group_val) {
                    group_top = group_top->next;
                }
                current->next = group_top;
            }
            current = current->next;
        }
        return dummy_head.next;
    }
};
