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
    int sum=0;
    
    void dfs(TreeNode* root, int ans){
        if(root==NULL)
            return;
        ans=(ans<<1)|root->val;
        if(root->left==NULL && root->right==NULL)
          sum+=ans;
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};