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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=head;
        while(curr && curr->next){
            prev->next=curr->next;
            curr->next=prev->next->next;
            prev->next->next=curr;
            
            prev=curr;
            curr=curr->next;
        }
        return dummy->next;
    }
};