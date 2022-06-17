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
    set<TreeNode*> s;
    int ans=0;
    
    void solve(TreeNode* root, TreeNode* par){
        if(root==NULL)
            return;
        solve(root->left, root);
        solve(root->right,root);
        if((par==NULL && s.find(root)==s.end())|| (s.find(root->left)==s.end() || s.find(root->right)==s.end())){
            s.insert(par);
            s.insert(root);
            s.insert(root->left);
            s.insert(root->right);
            ans++;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        s.insert(NULL);
        solve(root, NULL);
        return ans;
    }
};