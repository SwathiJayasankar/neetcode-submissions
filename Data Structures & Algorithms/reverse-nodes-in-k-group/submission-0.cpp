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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        //check if at least k nodes exist
        for(int i=0; i<k; i++){
            if(!temp){
                return head;
            }
            temp = temp->next;
        }

        //reverse k nodes
        ListNode* prev = NULL;
        ListNode* cur = head;
        for(int i=0; i<k; i++){
            ListNode* nextnd = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextnd;
        }

        //head is pointing to last node of the group
        // prev to first node of the grp
        // cur to first node of next grp
        head->next = reverseKGroup(cur, k);
        
        return prev;
    }
};
