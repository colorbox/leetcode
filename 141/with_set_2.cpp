// insertの返り値を利用して存在確認をする方法
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> reached;
        ListNode* current = head;
        while (current) {
            auto [it, inserted] = reached.insert(current);
            if (!inserted) { return true; }
            current = current->next;
        }
        return false;
    }
};
