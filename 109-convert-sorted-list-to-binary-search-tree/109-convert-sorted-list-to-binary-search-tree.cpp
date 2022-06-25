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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(ListNode* head, ListNode* tail){
        if(head==tail)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow;
        ListNode* l2=slow->next;
        TreeNode* root=new TreeNode(mid->val);
        mid->next=NULL;
        TreeNode* l=solve(head, mid);
        TreeNode* r=solve(l2, tail);
        root->left=l;
        root->right=r;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        return solve(head, NULL);
    }
};