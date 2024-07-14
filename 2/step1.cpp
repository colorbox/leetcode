/*
Time: 40:43
Space: O(N)
Time: O(N)

ローカル変数のアドレスを使ったりしてバグらせて仕切り直した結果時間がかかりすぎた。
リストの先頭から合算していたリストを作成し、最終的にそれを返す。
繰り上がりを考慮する必要がある。
繰り上がりが最後まで残ったときの処理を忘れておりそれを最後に追加。
l1かl2のどちらかを書き換える手段も会ったが、引数を書き換えるのはよくない + コードが無駄に複雑になりそうなのでやめた。
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode sentinel_node = ListNode();
        ListNode* sum_node = &sentinel_node;
        ListNode* left = l1;
        ListNode* right = l2;
        bool carry = false;
        while (left || right) {
            int sum = 0;
            if (left) {
                sum += left->val;
                left = left->next;
            }
            if (right) {
                sum += right->val;
                right = right->next;
            }
            if (carry) {
                sum++;
            }
            if (sum >= 10) {
                carry = true;
                sum %= 10;
            } else {
                carry = false;
            }

            ListNode* next_sum_node = new ListNode(sum);
            sum_node->next = next_sum_node;
            sum_node = next_sum_node;
        }
        if (carry) {
            ListNode* last = new ListNode(1);
            sum_node->next = last;
        }
        return sentinel_node.next;
    }
};
