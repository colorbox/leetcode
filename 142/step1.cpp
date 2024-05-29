/*
所要時間 31:00
Time: O(NlogN)
Space: O(N)

mapを使う解法自体は考慮できていたが、構文ミスでハマった。
これまで訪れたノードを記憶しておき、再訪したノードがあればそれを返すことでサイクルのループ開始ノードを返せる。

 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) { 
            return nullptr;
        }

        map<ListNode*, bool> visited;
        ListNode* current = head;
        while (current) {
            if (visited[current]) {
                return current;
            }
            visited[current] = true;
            current = current->next;
        }

        return nullptr;
    }
};
