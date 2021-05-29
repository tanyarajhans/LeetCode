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
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* r) {
        if(r==NULL)
            return ans;
        stack<TreeNode*> s;
        TreeNode* root=r;
      //  
        while(true){
            while(root){
                ans.push_back(root->val);
                s.push(root);
                root=(root->left);
            }
            if(!s.empty()){
                root=s.top();
                s.pop();
                root=root->right;
            }
            else break;
        }
        return ans;
    }
};