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
    int xl,yl,xp,yp;
    
    void dfs(TreeNode* root, int x, int y, int p, int l){
        if(root==NULL)
            return;
        if(root->val==x){
            xl=l;
            xp=p;
            return;
        }
        if(root->val==y){
            yl=l;
            yp=p;
            return;
        }
        dfs(root->left,x,y,root->val,l+1);
        dfs(root->right,x,y,root->val,l+1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,x,y,0,0);
        if(xl==yl && xp!=yp)
            return true;
        return false;
    }
};