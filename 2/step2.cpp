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
                carry = false;
            }
            if (sum >= 10) {
                carry = true;
                sum -= 10;
            }
            sum_node->next = new ListNode(sum);
            sum_node = sum_node->next;
        }
        if (carry) {
            sum_node->next = new ListNode(1);
        }
        return sentinel_node.next;
    }
};
