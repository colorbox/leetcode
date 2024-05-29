/*
https://discord.com/channels/1084280443945353267/1192728121644945439/1194203372115464272
を参考にstep4_floydを書き直した
>「機械の使い方の説明です。まず、青いランプが5つついていることを確認してください。ランプがついていなかった場合は、直ちに使用を中止して事務所に連絡してください。…長い使い方の説明…。」
>のほうが素直ですよね。
という説明がしっくりきた
早期returnをしたほうが考えること減ってわかりやすくなる。
`while(fast && fast->next)`という書き方にこだわってしまっていたので、step4時点でこれが見えてなかった。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (true) {
            if (!fast || !fast->next) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { 
                break;
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
