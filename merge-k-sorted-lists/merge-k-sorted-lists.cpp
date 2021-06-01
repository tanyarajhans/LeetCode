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
    
    struct comp{
        bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
            return NULL;
        if(n==1)
            return lists[0];
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        for(int i=0;i<n;i++){
            ListNode* head=lists[i];
            while(head!=NULL){
                ListNode* t=head->next;
                head->next=NULL;
                pq.push(head);
                head=t;
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* temp=dummy;
        while(!pq.empty()){
            temp->next=pq.top();
            pq.pop();
            temp=temp->next;
        }
        return dummy->next;
    }
};