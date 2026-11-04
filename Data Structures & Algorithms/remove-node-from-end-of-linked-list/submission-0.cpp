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
        ListNode dummy(-1, head);
        ListNode *curr = &dummy;
        ListNode *temp = &dummy;

        for(int i = 0; i<n; i++) {
            temp = temp->next;
        }

        while(temp->next){
            curr = curr->next;
            temp = temp->next;
        }

        temp = curr->next;
        curr->next = temp->next;
        delete temp;
        return dummy.next;
    }
};
