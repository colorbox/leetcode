class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode sentinel_node;
    ListNode* previous_node = &sentinel_node;
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
      digit += carry;
      carry = digit / 10;
      previous_node->next = new ListNode(digit % 10);
      previous_node = previous_node->next;
    }
    return sentinel_node.next;
  }
};
