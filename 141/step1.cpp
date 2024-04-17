// 早いのと遅いので競争をするというネタを知っていたので、それをそのまま実装。
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && slow) {
            fast = fast->next;
            if (!fast) {
                return false;
            }
            fast = fast->next;

            slow = slow->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
