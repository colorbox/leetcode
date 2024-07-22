/*
反転したリストの末尾につけるためと、最終的にreturnするための反転リストの先頭を同時に返すパターン。
関数の中で着目呈しているノード(head)を、それ以降の反転されたリストの末尾に接続することで反転を実現する。

https://github.com/goto-untrapped/Arai60/pull/27/files/14646ec0859dd9411e6983bf6c63e6f15a1f9f32#r1641596128
>何も渡さずに、6番目以降をひっくり返したものを返してもらう。
*/
class Solution {
public:
  std::tuple<ListNode*, ListNode*> recursiveReverseList(ListNode* head) {
    if (!head) {
      return std::make_tuple(nullptr, nullptr);
    }
    if (!head->next) {
      return std::make_tuple(head, head);
    }
    ListNode* top;
    ListNode* last;
    std::tie(top, last) = recursiveReverseList(head->next);
    head->next = nullptr;
    last->next = head;

    return std::make_tuple(top, head);

  }
  ListNode* reverseList(ListNode* head) {
    ListNode* top;
    ListNode* last;
    std::tie(top, last) = recursiveReverseList(head);
    return top;
  }  
};
