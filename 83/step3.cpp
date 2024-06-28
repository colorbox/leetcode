/*
2つ目のwhileに不要な記述があったので削除
リストを先頭から見ていき、currentとその次の要素が同地な場合は削除ループを回す
削除が完了したらcurrentを進める
最後にheadを返して完了
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current) {
            while (current->next && current->val == current->next->val) {
                current->next = current->next->next;
            }
            current = current->next;
        }
        return head;
    }
};
