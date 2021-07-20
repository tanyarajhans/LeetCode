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
    vector<vector<int>> ans;
    
    bool solve(TreeNode* root, int t, int sum, vector<int> v){
        if(root==NULL)
            return false;
        sum+=root->val;
        v.push_back(root->val);
        if(sum==t && root->left==NULL && root->right==NULL){
            ans.push_back(v);
            return true;
        }
            
        bool l=solve(root->left, t, sum, v);
        bool r=solve(root->right, t, sum, v);
        return l||r;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<int> v;
        solve(root, t, 0, v);
        return ans;
    }
};