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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        ListNode* curr=head;
        int l=0;
        while(curr->next!=NULL){
            curr=curr->next;
            l++;
        }
        l++;
        curr->next=head;
        k%=l;
        int g=l-k;
        curr=head;
        for(int i=0;i<g-1;i++){
            curr=curr->next;
        }
        ListNode* newHead=curr->next;
        curr->next=NULL;
        head=newHead;
        return head;
    }
};