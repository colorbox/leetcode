/*
再帰の返り値が使用されるように修正
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* current = head;
        while (current && current->next && current->val == current->next->val) {
            current = current->next;
        }
        current = current->next;
        head->next = deleteDuplicates(current);
        return head;
    }
};
