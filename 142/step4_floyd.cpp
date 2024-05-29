/*
step3_floydにてwhileの条件にしていた`(fast && fast->next)`とその直後の`(!fast || !fast->next)`は反転しているだけで実質同じという指摘を受けて書き直す。
Pythonのようにwhileに対してelseをつけられないので、while(true)のループの中でif-elseで分岐させる。
while(true)の中で分岐させると、ネストが深くなってしまい個人的に避けている書き方だったが、こちらのほうがifが少なくできて読みやすい

*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (true) {
          if (fast && fast->next) {
              slow = slow->next;
              fast = fast->next->next;
              if (slow == fast) {
                  break;
              }
          } else {
              return nullptr;
          }
        }

        ListNode* from_head = head;
        while (slow != from_head) {
            slow = slow->next;
            from_head = from_head->next;
        }
        return from_head;
    }
};
