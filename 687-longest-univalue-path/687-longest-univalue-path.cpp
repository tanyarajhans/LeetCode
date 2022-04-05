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
    int ans;
    
    int solve(TreeNode* root, int v){
        if(root==NULL)
            return 0;
        int l=solve(root->left, root->val);
        int r=solve(root->right, root->val);
        ans=max(ans, l+r);
        if(root->val==v)
            return max(l+1,r+1);
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL)
           return 0;
        solve(root, root->val);
        return ans;
    }
};