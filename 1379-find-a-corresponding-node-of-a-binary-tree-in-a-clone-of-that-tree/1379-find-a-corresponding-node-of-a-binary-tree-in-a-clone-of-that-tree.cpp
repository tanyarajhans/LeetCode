/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    
    void inorder(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL)
            return;
        inorder(original->left, cloned->left, target);
        if(original==target)
        {
            ans=cloned;
            return;
        }
        inorder(original->right, cloned->right, target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inorder(original, cloned, target);
        return ans;
    }
};