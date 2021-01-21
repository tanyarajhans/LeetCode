/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
​
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int par=root->val;
        int l=p->val;
        int r=q->val;
        if(l>par && r>par)
            return lowestCommonAncestor(root->right, p, q);
        else if(l<par && r<par)
            return lowestCommonAncestor(root->left, p, q);
        else return root;
    }
};
