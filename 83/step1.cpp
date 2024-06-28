/**
4:30
Time: O(N)
Space: O(1)

リストの性質上、削除すべき要素は隣接している。
リストを頭から終わりまでチェックし、不要要素を削除していくことで実現できると判断。

 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current) {
            if (!current || !current->next) {
                return head;
            }
            if (current->val == current->next->val) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};
