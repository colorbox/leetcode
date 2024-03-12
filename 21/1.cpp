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

        ListNode *ret;
        if(list1->val < list2->val){
            ret = list1;
            list1 = list1->next;
        } else{
            ret = list2;
            list2 = list2->next;
        }
        ListNode *current = ret;

        cout << current->val << endl;

        while(list1 != nullptr || list2 != nullptr){
            if(list1 == nullptr){
                current->next = list2;
                return ret;
            }

            if(list2 == nullptr){
                current->next = list1;
                return ret;
            }

            if(list1->val < list2->val){
                current->next = list1;
                list1 = list1->next;
            }else{
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        return ret;
    }
};
