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
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* f=dummy;
        ListNode* s=dummy;
        int k=0;
        while(k<n){
            f=f->next;
            k++;
        }
        while(f->next!=NULL){
            f=f->next;
            s=s->next;
        }
        s->next=s->next->next;
        return dummy->next;
    }
};