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
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        ListNode* t=head;
        while(t!=NULL){
           v.push_back(t);
           t=t->next;
        }
        
        int l=0,r=v.size()-1;
        ListNode* k=new ListNode();
        while(l<=r){
            ListNode* left=v[l];
            ListNode* right=v[r];
            left->next=right;
            k->next=left;
            k=right;
            l++;
            r--;
        }
        k->next=NULL;
    }
};
