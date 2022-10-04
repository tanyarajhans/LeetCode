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
    vector<TreeNode*> ans;
    
    void solve(TreeNode* &root, set<int> &del){
        if(!root)
            return;
        solve(root->left, del);
        solve(root->right, del);
        if(del.find(root->val)!=del.end()){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            root=NULL;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root)
            return ans;
        set<int> del;
        for(auto &x: to_delete)
            del.insert(x);
        solve(root, del);
        if(root)
            ans.push_back(root);
        return ans;
    }
};