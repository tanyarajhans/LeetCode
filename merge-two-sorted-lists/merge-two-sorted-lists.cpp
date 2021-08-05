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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
            return NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val>l2->val)
            swap(l1,l2);
        ListNode* x=l1;
        ListNode* y=l2;
        ListNode* dummy=new ListNode(0);
        dummy->next=NULL;
        ListNode* temp=dummy;
        while(x!=NULL && y!=NULL){
            if(x->val<=y->val){
                temp->next=x;
                temp=temp->next;
                x=x->next;
            }
            else{
                temp->next=y;
                temp=temp->next;
                y=y->next;
            }
        }
        while(x!=NULL){
            temp->next=x;
            temp=temp->next;
            x=x->next;
        }
        while(y!=NULL){
            temp->next=y;
            temp=temp->next;
            y=y->next;
        }
        return dummy->next;
    }
};