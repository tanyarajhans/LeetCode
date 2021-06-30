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
    ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode *p1=head,*p2=head;
            ListNode *first=NULL,*cur=head;
            int n=0;
            while(p1)
            {
                p1=p1->next;
                n++;
            }
            n=n/k;
            if(n==0 || k==1) 
                return head;
            for(int i=0;i<n;i++)
            {
                ListNode *prev=NULL,*next=NULL;
                int l=1;
                p1=cur;
                while(l++<=k)
                {
                    next=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=next;
                }
                if(i>=1)
                    first->next=prev;
                else
                    p2=prev;
                first=p1;
            }
            first->next=cur;
            return p2;
    }
};