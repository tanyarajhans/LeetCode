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
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        while(root!=NULL){
            if(root->left!=NULL){
                TreeNode* tl=root->left;
                TreeNode* curr=tl;
                while(curr->right!=NULL)
                    curr=curr->right;
                curr->right=root->right; //Morris Traversal
                root->left=NULL;
                root->right=tl;
            }
            root=root->right;
        }
    }
};