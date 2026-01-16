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
    struct compare {
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // step 1: push all heasd
        for(auto list : lists){
            if(list) pq.push(list);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        // step 2: process heap
        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if(node->next){
                pq.push(node->next);
            }
        }

        return dummy.next; // time= O(n log k) and space = O(k)
    }
};