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
    
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp=dummy;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL)
             pq.push(lists[i]);
        }
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            temp->next=curr;
            temp=temp->next;
            if(temp->next){
                pq.push(temp->next);
            }
        }
        return dummy->next;
    }
};