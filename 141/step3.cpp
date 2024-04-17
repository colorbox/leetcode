class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }

        auto fast = head->next;
        auto slow = head;

        while (fast && fast->next) {
            if (fast == slow) {
                return true;
            }

            fast = fast->next->next;
            slow = slow->next;
        }

        return false;
    }
};
