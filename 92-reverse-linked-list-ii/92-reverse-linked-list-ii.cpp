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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
            return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* beforeCurr=dummy;
        ListNode* curr=head;
        int x=1;
        while(x<left){
            beforeCurr=curr;
            curr=curr->next;
            x++;
        }
        ListNode* prev=NULL, *nex=NULL;
        while(x<right){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
            x++;
        }
        beforeCurr->next->next=curr->next;
        curr->next=prev;
        beforeCurr->next=curr;
        return dummy->next;
    }
};