/*
Time: 21:00
Space: O(1)
Time: O(N)

先頭要素も削除されうるため、返すためのダミーノードを用意する。
リスト全体をチェックしていくwhileループと、重複要素を削除するwhileループを入れ子にする。
重複要素はすべて消さないといけないので、判定するためにvalを残す。
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy_head = new ListNode(0, head);
        ListNode* current = dummy_head;
        while (current) {
            while (current->next && current->next->next && current->next->val == current->next->next->val) {
                int target_val = current->next->val;
                while (current->next->val == target_val) {
                  current->next = current->next->next;
                  if (!current->next) {
                    break;
                  }
                }                
            }
            current = current->next;
        }
        ListNode* result = dummy_head->next;
        delete dummy_head;
        return result;
    }
};
