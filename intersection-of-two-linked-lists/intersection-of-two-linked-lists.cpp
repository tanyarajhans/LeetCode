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
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        if(l1==NULL || l2==NULL)
            return NULL;
        ListNode* h1=l1;
        ListNode* h2=l2;
        while(h1!=h2){
            if(h1!=NULL)
                h1=h1->next;
            else h1=l2;
            if(h2!=NULL)
                h2=h2->next;
            else
                h2=l1;
        }
        return h1;
    }
};