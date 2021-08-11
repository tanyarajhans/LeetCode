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
    unordered_map<int, int> m;
    
    bool solve(TreeNode* root, int k){
        if(root==NULL)
            return 0;
        int d=k-root->val;
        if(m.find(d)!=m.end())
            return true;
        m[root->val]++;
        return solve(root->left, k) || solve(root->right, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return 0;
        return solve(root, k);
    }
};