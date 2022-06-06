/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return NULL;
        ListNode *x=headA, *y=headB;
        while(x!=y){
            x=x->next;
            y=y->next;
            if(x==y)
                break;
            if(x==NULL)
                x=headB;
            if(y==NULL)
                y=headA;
        }
        return x;
    }
};