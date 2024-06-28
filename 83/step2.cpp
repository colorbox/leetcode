/*
他の回答者のコードやレビューを読んで修正
whileを入れ子にするとにた処理をまとめれる
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;

        while (current) {
            while (current && current->next && current->val == current->next->val) {
                current->next = current->next->next;
            }
            current = current->next;
        }
        return head;
    }
};
