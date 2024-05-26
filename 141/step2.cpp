// whileの中をなるべくシンプルにするため、fast returnやfastの初期化部分を修正
// while中のfastの状態チェックをwhileの継続条件に取り込む
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }

        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast && fast->next) {
            if (slow == fast) {
                return true;
            }

            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
};
