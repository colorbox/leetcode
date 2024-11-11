/*
所要時間 8:01
Time: O(n)
Space: O(1)
解説や他の人のコードを読んでFloydアルゴリズムで実装。
サイクルがあh字丸までの距離、1サイクル分の距離、サイクル開始からfast,slowが出会うまでの距離、fast/slowが出会うまでの進行距離を考慮すると
fast/slowが出会った場所からサイクルの開始までの距離と
リストの先頭からサイクルの開始までの距離が等しいことが分かるため、それを求めた。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) { 
            return nullptr;
        }
        ListNode* slow = head->next;
        if (!slow) {
            return nullptr;
        }

        ListNode* fast = head->next->next;
        if (!fast) {
            return nullptr;
        }

        while (slow != fast) {
            slow = slow->next;
            if (!fast || !fast->next) {
                return nullptr;
            }

            fast = fast->next->next;
        }

        ListNode *current = head;
        while (slow != current) {
            slow = slow->next;
            current = current->next;
        }

        return current;
    }
};
