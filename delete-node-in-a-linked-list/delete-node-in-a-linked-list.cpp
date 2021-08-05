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
    void deleteNode(ListNode* node) {
        ListNode* nx=node->next;
        int v=nx->val;
        node->val=v;
        node->next=node->next->next;
        delete(nx);
    }
};