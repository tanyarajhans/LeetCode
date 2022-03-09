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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp=head;
        ListNode* prev=dummy;
        
        while(temp!=NULL){
            if(temp->next!=NULL && temp->val == temp->next->val){
                while(temp->next!=NULL && temp->val == temp->next->val)
                    temp=temp->next;
                prev->next=temp->next;
            }
            else if(prev->next!=NULL)
                prev=prev->next;
            temp=temp->next;      
        }
        return dummy->next;
    }
};