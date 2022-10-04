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
    bool solve(TreeNode* root, int s, int t){
        if(!root){
            return false;
        }
        if(!root->left && !root->right){
            s+=root->val;
            if(s==t)
                return true;
        }
        bool x=solve(root->left, s+root->val, t);
        bool y=solve(root->right, s+root->val, t);
        return x|y;
    }
    
    bool hasPathSum(TreeNode* root, int target) {
        if(!root){
            return false;
        }
        return solve(root,0,target);
    }
};