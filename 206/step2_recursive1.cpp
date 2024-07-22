/*
一番最後の再帰ですべてを返すパターン
iterativeな解法を再帰で書いたようなコード

https://github.com/goto-untrapped/Arai60/pull/27/files/14646ec0859dd9411e6983bf6c63e6f15a1f9f32#r1641789968
> 頭から5番目までひっくり返した物を渡して、全部がひっくり返ったものを返してもらう。

*/
class Solution {
public:
  ListNode* recursiveReverseList(ListNode* head, ListNode* previous) {
    if (!head) {
      return previous;
    }
    ListNode* temp = head->next;
    head->next = previous;
    return recursiveReverseList(temp, head);
  }

  ListNode* reverseList(ListNode* head) {
    return recursiveReverseList(head, nullptr);
  }  
};
