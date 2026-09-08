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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* temp = head;
        while (temp){
            nodes.push_back(temp);
            temp = temp->next;
        }

        int rem = nodes.size() - n;

        if (rem == 0){
            head = head->next;
        } else if (rem + 1 > (nodes.size() - 1)){
            nodes[rem-1]->next = nullptr;
        } else {
            nodes[rem-1]->next = nodes[rem + 1];
        }

        return head;
    }
};
