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
    set<TreeNode*> cov;
    
    void dfs(TreeNode* root, TreeNode* p){
        if(root==NULL)
            return;
        dfs(root->left,root);
        dfs(root->right,root);
        if(p==NULL && cov.find(root)==cov.end() || cov.find(root->left)==cov.end() || cov.find(root->right)==cov.end()){
            ans++;
            cov.insert(root);
            cov.insert(p);
            cov.insert(root->left);
            cov.insert(root->right);
        }
    }
    
    int minCameraCover(TreeNode* root) {
        ans=0;
        cov.insert(NULL);
        dfs(root,NULL);
        return ans;
    }
};