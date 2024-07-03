/*
再帰によるコードを追加、同一値のグループごとに再帰させる。
返り値を活用できていないのが気になる。
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        while (head && head->next && head->val == head->next->val) {
            head->next = head->next->next;
        }
        deleteDuplicates(head->next);
        return head;
    }
};
