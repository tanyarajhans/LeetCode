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
    pair<int, int> ans;
    
    pair<int, int> dfs(TreeNode* root){
        if(root==NULL)
            return {0,0};
        pair<int, int> l=dfs(root->left);
        pair<int, int> r=dfs(root->right);
        int rob = root->val + l.second+r.second;
        int notrob = max(l.first, l.second)+max(r.first,r.second);
        return {rob, notrob};
    }
    
    int rob(TreeNode* root) {
        ans=dfs(root);
        return max(ans.first, ans.second);
    }
};