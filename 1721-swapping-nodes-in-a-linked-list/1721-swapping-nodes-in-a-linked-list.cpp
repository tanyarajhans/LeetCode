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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        cout<<n<<endl;
        if(n==1)
            return head;
        int d=n-k+1;
        ListNode *c1, *c2;
        temp=head;
        n=1;
        while(temp!=NULL){
            if(n==k)
                c1=temp;
            if(n==d)
                c2=temp;
            temp=temp->next;
            n++;
        }
        swap(c1->val,c2->val);
        return head;
    }
};