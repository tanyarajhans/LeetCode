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
    
    ListNode* merge(ListNode* x, ListNode* y){
        if(x==NULL && y==NULL)
            return NULL;
        if(x==NULL)
            return y;
        if(y==NULL)
            return x;
        ListNode* dummy = new ListNode(0);
        ListNode* temp=dummy;
        ListNode* a=x;
        ListNode* b=y;
        while(a && b){
            if(a->val<b->val){
                temp->next=a;
                a=a->next;
            }
            else{
                temp->next=b;
                b=b->next;
            }
            temp=temp->next;
        }
        if(!a)
            temp->next=b;
        if(!b)
            temp->next=a;
        return dummy->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* t=head;
        while(fast!=NULL && fast->next!=NULL){
            t=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        t->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(slow);
        return merge(left, right);
    }
};