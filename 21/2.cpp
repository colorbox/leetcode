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
        if(list1 == nullptr)return list2;
        if(list2 == nullptr)return list1;

        // always list1 <= list2
        if(list1->val > list2->val){
            swap(list1, list2);
        }

        ListNode* ret = list1;
        list1 = list1->next;

        ListNode *current = ret;

        while(list1 != nullptr && list2 != nullptr){
            // always list1 <= list2
            if(list1->val > list2->val){
                swap(list1, list2);
            }

            current->next = list1;
            list1 = list1->next;

            current = current->next;
        }

        if(list1 == nullptr){
            current->next = list2;
            return ret;
        }

        if(list2 == nullptr){
            current->next = list1;
            return ret;
        }

        return ret;
    }
};
