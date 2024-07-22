/*
変数名などを若干修正。
ループの中で、操作対象のノードを順に辿る。
南京錠と鎖の例えを借りると、鍵を付け替える対象の鉄輪を各ループの中で操作する。
各ループの中で、操作対象の鉄輪を一つ前の鉄輪に付け替える。
そのままだと、次のループで必要となる「次の操作対象の鉄輪」が取り出せなくなるので、ループの中で事前に取り出して保持しておく
次のループに移る前に、操作対象の鉄輪と、その「前の鉄輪」を更新する。
*/
class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode* previous_node = nullptr;
    ListNode* operating_node = head;
    while (operating_node) {
      ListNode* preserved_next_node = operating_node->next;
      operating_node->next = previous_node;
      previous_node = operating_node;
      operating_node = preserved_next_node;
    }
    return previous_node;
  }  
};
