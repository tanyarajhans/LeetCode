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
    ListNode* partition(ListNode* head, int x) {
        ListNode* x1=new ListNode(0); //all nodes less than x
        ListNode* x2=new ListNode(0); //all nodes >=x
        ListNode* t1=x1;
        ListNode* t2=x2;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                t1->next=temp;
                t1=temp;
            }
            else{
                t2->next=temp;
                t2=temp;
            }
            temp=temp->next;
        }
        t2->next=NULL;
        t1->next=x2->next;
        return x1->next;
    }
};