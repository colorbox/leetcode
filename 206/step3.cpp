class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* node = head;
    while (node) {
      ListNode* preserved = node->next;
      node->next = prev;
      prev = node;
      node = preserved;
    }
    return prev;
  }
};
