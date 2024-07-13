/*
レビュー指摘を受けて修正したコード
3重のwhileはそれで解けなくはないしパスするものの読みづらい
ifの代わりにwhileを使うと連続した同値グループをそのブロック内で処理できる利点があるが流石に3重whileは読みづらいのでダメ
ifを使用して、外側のループの中で処理する。
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy_node = ListNode(-1, head);
        ListNode* inspecting_node = &dummy_node;
        while (inspecting_node) {
            ListNode* group_top = inspecting_node->next;
            if (group_top && group_top->next && group_top->val == group_top->next->val) {
                int group_val = group_top->val;
                while (group_top && group_top->val == group_val) {
                    inspecting_node->next = group_top->next;
                    group_top = group_top->next;
                }
            } else {
                inspecting_node = inspecting_node->next;
            }
        }
        return dummy_node.next;
    }
};
