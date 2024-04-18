// 他の人のコードを下に更に修正したもの
// whileブロックの最初に`fast == slow`を持ってきていたために、fast/slowの初期化を変えたり、headのnullチェックをしていたが、fast==slowのチェック位置を変えるだけでそれらの処理をなくせた
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};
