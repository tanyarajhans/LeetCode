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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        if(root==NULL)
            return ans;
        TreeNode* curr=root;
        TreeNode* pre=NULL;
        while(!s.empty() || curr){
            if(curr){
                s.push(curr);
                curr=curr->left;
            }
            else{
                curr=s.top();
                if(curr->right==NULL || curr->right==pre){
                    ans.push_back(curr->val);
                    s.pop();
                    pre=curr;
                    curr=NULL;
                }
                else
                    curr=curr->right;
            }
        }
        return ans;
    }
};