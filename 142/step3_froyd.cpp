/*
fast && fast->next
という記法がその場で出てこなかった
if (fast != slow)
という記法にこだわってしまったため
終了条件がslow==fastだったのでそれをそのままループの継続条件にしてしまった

基本的にリスト内にcycleがなければよい( = もしあればその場でreturn nullptrできる)
ので(fast != slow)というのは実はループを回すうえでは重要ではない
なので、先行するfastがnullとならないことさえ確認できればよい
この書き方に固執してしまうとslowとfastの初期化が面倒になり、それに伴って本来不要な早期returnが必要となってしまう
fast == slowはループの終了条件として使うほうが無駄を減らせて自然なコードになる。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }

        if (!fast || !fast->next) {
            return nullptr;
        }

        ListNode* from_head = head;
        while (slow != from_head) {
            slow = slow->next;
            from_head = from_head->next;
        }

        return from_head;
    }
};
