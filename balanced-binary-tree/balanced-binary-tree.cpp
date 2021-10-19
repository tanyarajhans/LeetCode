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
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;
        int l=solve(root->left);
        if(l==-1)
            return -1;
        int r=solve(root->right);
        if(r==-1)
            return -1;
        if(abs(l-r)>1)
            return -1;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        if(solve(root)==-1)
            return false;
        return true;
    }
};