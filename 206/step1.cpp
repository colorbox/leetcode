/**
Time: 10:21
Space: O(1)
Time: O(N)

stackを利用して解こうとしてハマってしまう
ひとまずポインタを用いて素朴に解いた
 */
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current) {
      ListNode* temp_next = current->next;
      current->next = prev;
      prev = current;
      current = temp_next;
    }
    return prev;
  }  
};
