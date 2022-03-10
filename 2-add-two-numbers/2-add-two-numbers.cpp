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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
            return NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        int carry=0;
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(l1!=NULL || l2!=NULL){
            int x=0,y=0;
            if(l1!=NULL)
                x=l1->val;
            if(l2!=NULL)
                y=l2->val;
            int s=x+y+carry;
            carry=s/10;
            temp->next=new ListNode(s%10);
            temp=temp->next;
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
        }
        if(carry)
            temp->next=new ListNode(carry);
        return dummy->next;
    }
};