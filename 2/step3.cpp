class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode sentinel_node = ListNode();
        ListNode* sum_node = &sentinel_node;
        ListNode* left = l1;
        ListNode* right = l2;
        bool carry  =false;
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
            if (sum>=10) {
                sum -= 10;
                carry = true;
            }
            ListNode* next_sum_node = new ListNode(sum);
            sum_node->next = next_sum_node;
            sum_node = sum_node->next;
        }
        if (carry) {
            ListNode* last_sum_node = new ListNode(1);
            sum_node->next = last_sum_node;
        }
        return sentinel_node.next;
    }
};
