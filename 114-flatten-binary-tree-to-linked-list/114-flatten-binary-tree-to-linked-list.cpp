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
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        while(root){
            if(root->left && root->right){
            TreeNode* t=root->left;
            while(t->right)
                t=t->right;
            t->right=root->right; //look at nodes 4,5,6
          }
          if(root->left){
              root->right=root->left;
          }
            root->left=NULL;
            root=root->right;
        }
    }
};