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
    int solve(TreeNode* root, int cur, int& sum){
        if(!root)
            return 0;
        int cs=cur+root->val;
        return (sum==cs) + solve(root->left,cs,sum) + solve(root->right,cs,sum);
        
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        return solve(root, 0, sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
    }
};