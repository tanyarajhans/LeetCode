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
    
    TreeNode* lca(TreeNode* l1, TreeNode* l2, TreeNode* root){
        if(root==NULL || root==l1 || root==l2)
            return root;
        TreeNode* l=lca(l1,l2,root->left);
        TreeNode* r=lca(l1,l2,root->right);
        if(l&&r)
            return root;
        if(!l)
            return r;
        return l;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL)
            return NULL;
        TreeNode* f, *s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(i==0)
                    f=curr;
                if(i==k-1)
                    s=curr;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return lca(f,s, root);
    }
};