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
struct cmp{
    bool operator()(const ListNode* a, const ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(ListNode* l: lists){
            if(l) pq.push(l);
        }

        ListNode dummy(-1);
        ListNode* curr = &dummy;

        while(!pq.empty()){
            auto node = pq.top(); pq.pop();
            curr->next = node;
            curr = curr->next;

            if(node && node->next) pq.push(node->next);
        }

        return dummy.next;
    }
};
