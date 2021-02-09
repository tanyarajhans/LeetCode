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
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        stack<TreeNode*> s;
        TreeNode* temp=root;
        while(!s.empty() || temp!=NULL){
            while(temp!=NULL){
                s.push(temp);
                temp=temp->right;
            }
            temp=s.top();
            s.pop();
            sum+=temp->val;
            temp->val=sum;
            temp=temp->left;
        }
        return root;
    }
};