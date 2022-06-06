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
            if(x)
                x=x->next;
            else
                x=headB;
            if(y)
                y=y->next;
            else
                y=headA;
        }
        return x;
    }
};