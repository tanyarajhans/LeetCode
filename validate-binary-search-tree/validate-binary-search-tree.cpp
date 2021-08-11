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
    bool solve(TreeNode* root, long long mini, long long maxi){
        if(root==NULL)
            return true;
        if(root->val<=mini || root->val>=maxi)
            return false;
        bool l=solve(root->left, mini, root->val);
        bool r=solve(root->right, root->val, maxi);
        return l&&r;
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root, -1e15, 1e15);
    }
};