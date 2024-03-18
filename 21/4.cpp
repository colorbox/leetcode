/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode root = ListNode();
        ListNode *current = &root;

        ListNode *smaller = list1;
        ListNode *bigger = list2;

        while (smaller && bigger) {
            if (smaller->val > bigger->val) {
                swap(smaller, bigger);
            }

            current->next = smaller;
            current = current->next;
            smaller = smaller->next;
        }

        if (smaller) {
            current->next = smaller;
        }
        if (bigger) {
            current->next = bigger;
        }

        return root.next;
    }
};
