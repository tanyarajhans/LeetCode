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
    bool solve(TreeNode* x, TreeNode* y){
        if(x==NULL && y==NULL)
            return true;
        if(x==NULL || y==NULL)
            return false;
        if(x->val!=y->val)
            return false;
        
        return solve(x->right, y->left) && solve(x->left, y->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return solve(root, root);
    }
};