class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode sentinel_node;
    ListNode* adding_node = &sentinel_node;
    int carry = 0;
    while (l1 || l2 || carry) {
      int digit = 0;
      if (l1) {
        digit += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        digit += l2->val;
        l2 = l2->next;
      }
      if (carry) {
        digit++;
      }
      carry = digit / 10;

      if (digit >= 10) {
        digit = digit - 10;
      }
      adding_node->next = new ListNode(digit);
      adding_node = adding_node->next;
    }
    return sentinel_node.next;
  }
};
