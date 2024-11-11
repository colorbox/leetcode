/*
mapではなくsetを使い、存在確認にcontainsを使用するよに修正。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> visited;
        ListNode* current = head;

        while (current) {
            if (visited.contains(current)) {
                return current;
            }

            visited.insert(current);
            current = current->next;
        }

        return nullptr;
    }
};
