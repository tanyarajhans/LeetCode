/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* prev=NULL;
        ListNode* t=head;
        while(m>1){
            prev=t;
            t=t->next;
            m--;
            n--;
        }
        ListNode* c1=t;
        ListNode* p1=prev;
        ListNode* t1=NULL;
        while(n>0){
            t1=t->next;
            t->next=prev;
            prev=t;
            t=t1;
            n--;
        }
       if(p1!=NULL)
           p1->next=prev;
        else
            head=prev;
        c1->next=t;
        return head;
    }
};
