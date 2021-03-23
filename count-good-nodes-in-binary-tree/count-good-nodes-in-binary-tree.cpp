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
    void solve(TreeNode* root, int val, int &ans){
        if(root==NULL)
            return;
        if(root->val>=val){
                val=root->val;
                ans++;
        }   
        solve(root->left, val, ans);
        solve(root->right, val, ans);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        solve(root, INT_MIN, ans);
        return ans;
    }
};