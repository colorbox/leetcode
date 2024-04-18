// チェック済みのノードを記憶しておく解法のコード
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> reached;
        ListNode* current = head;
        while (current) {
            if (reached.count(current)) {
                return true;
            }
            reached.insert(current);
            current = current->next;
        }
        return false;
    }
};
