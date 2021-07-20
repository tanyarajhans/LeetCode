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
    bool solve(TreeNode* root, int t, int sum){
        if(root==NULL)
            return false;
        sum+=root->val;
        if(sum==t && root->left==NULL && root->right==NULL)
            return true;
        bool l=solve(root->left, t, sum);
        bool r=solve(root->right, t, sum);
        return l||r;
    }
    bool hasPathSum(TreeNode* root, int t) {
        return solve(root, t, 0);
    }
};