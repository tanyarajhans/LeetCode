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
    set<int> s;
    vector<TreeNode*> ans;
    
    TreeNode* solve(TreeNode* root, bool isRoot){
        if (root == NULL)
            return NULL;
        bool sd=(s.find(root->val) != s.end());
        if(isRoot && !sd)
            ans.push_back(root);
        root->left=solve(root->left, sd);
        root->right=solve(root->right, sd);
        return sd==true? NULL:root;     
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i: to_delete)
            s.insert(i);
        solve(root, true);
        return ans;
    }
};