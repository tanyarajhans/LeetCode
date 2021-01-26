/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(string s, vector<string> &ans, TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(s);
            return;
        }
        if(root->right){
            traverse(s+ "->"+ to_string(root->right->val),ans,root->right);
        }
        if(root->left){
            traverse(s+ "->"+ to_string(root->left->val),ans,root->left);
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL)
            return ans;
        string s=to_string(root->val);
        traverse(s, ans, root);
        return ans;  
    }
};
