/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)
            return NULL;
        if(root==p || root==q)
            return root;
        TreeNode* l=lca(root->left,p,q);
        TreeNode* r=lca(root->right,p,q);
        if(l && r)
            return root;
        if(l)
            return l;
        return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        return lca(root,p,q);
    }
};