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
        ListNode dummy(0);
        ListNode* tail = &dummy;
        ListNode* i1 = list1;
        ListNode* i2 = list2;

        while ((i1 != nullptr) && (i2 != nullptr)){
            if (i1->val <= i2->val){
                tail->next = i1;
                i1 = i1->next;
            } else {
                tail->next = i2;
                i2 = i2->next;
            }
            tail = tail->next;
        }
        tail->next = (i1 != nullptr) ? i1 : i2;
        
        return dummy.next;
        
    }
};
