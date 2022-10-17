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
    int ans=0;
    vector<int> solve(TreeNode* root){
       if(!root)
           return {0,1,INT_MIN,INT_MAX}; //BSTsum, isBST, max, min
        auto l=solve(root->left);
        auto r=solve(root->right);
        int x=root->val;
        if(l[1] && (!root->right || x<r[3]) && (!root->left || x>l[2])){
            ans=max(ans, x+l[0]+r[0]);
            int maxi, mini;
            if(!root->left)
                mini=x;
            else
                mini=l[3];
            if(!root->right)
                maxi=x;
            else
                maxi=r[2];
            return {x+l[0]+r[0], 1, maxi, mini};
        }
        return {0,0,0,0};
    }
    
    int maxSumBST(TreeNode* root) {
        if(!root)
            return 0;
        solve(root);
        return ans;
    }
};