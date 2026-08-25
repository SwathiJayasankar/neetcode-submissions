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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // min heap {val, node} - finding min from each sorted ll

        priority_queue< pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>> > pq;

        for(ListNode* node : lists){
            if(node)
                pq.push({node->val, node});
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!pq.empty()){
            auto [value, node] = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            // add next node from the same ll
            if(node->next){
                pq.push({node->next->val, node->next});
            }
        }
        return dummy->next;
    }
};
