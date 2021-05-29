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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &ps, int is, int ie) {
         if(ps<0 || is>ie)
             return NULL;
         
         TreeNode* root= new TreeNode(preorder[ps]);
      //   if(is==ie)
     //      return root;
         ps--;
         int index;
         for(int i=is; i<=ie;i++){
             if(root->val==inorder[i]){
                 index=i;
                 break;
             }
         }
         
         
         root->right=build(preorder,inorder,ps, index+1, ie);
         root->left=build(preorder,inorder,ps,is, index-1);
         
         return root;
     }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& post) {
        int m=post.size()-1;
        return build(post, inorder,m ,0, inorder.size()-1);
    }
};