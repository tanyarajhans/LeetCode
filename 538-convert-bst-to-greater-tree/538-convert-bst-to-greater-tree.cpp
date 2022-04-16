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
    int v=0;
    void solve(TreeNode* root){
        if(root==NULL)
            return;
        solve(root->right);
        v+=root->val;
        root->val=v;
        solve(root->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        solve(root);
        return root;
    }
};