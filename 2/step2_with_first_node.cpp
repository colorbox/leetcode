/*
first_nodeをそのままreturnする実装。
ノードの数値としてありえない-1で、初回処理を判定。
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first_node = new ListNode(-1);
        ListNode* sum_node = first_node;
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
                carry = false;
            }
            if (sum >= 10) {
                carry = true;
                sum -= 10;
            }
            if (sum_node->val == -1) {
                sum_node->val = sum;
            } else {
                sum_node->next = new ListNode(sum);
                sum_node = sum_node->next;
            }
        }
        if (carry) {
            sum_node->next = new ListNode(1);
        }
        return first_node;
    }
};
