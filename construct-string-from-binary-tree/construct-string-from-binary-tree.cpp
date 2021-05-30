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
    string tree2str(TreeNode* root) {
        if(root==NULL)
            return "";
        string s=to_string(root->val);
        if(root->left){
            s+='(';
            s+=tree2str(root->left);
            s+=')';
        }
        else if(root->right){
            s+="()";
        }
        if(root->right){
            s+='(';
            s+=tree2str(root->right);
            s+=')';
        }
        return s;
    }
};