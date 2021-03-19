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
    
    vector<int> dfs(TreeNode* root){
        if(root==NULL){
            return {true,0,0,0};
        }
        vector<int> l(dfs(root->left));
        vector<int> r(dfs(root->right));
        if((l[0]==true && (root->left==NULL || root->val>l[3])) && (r[0]==true && (root->right==NULL || root->val<r[2]))){
            int s=root->val+l[1]+r[1];
            ans=max(ans,s);
            int mini=0,maxi=0;
            if(root->left==NULL)
                mini=root->val;
            else
                mini=l[2];
            if(root->right==NULL)
                maxi=root->val;
            else
                maxi=r[3];
            return {true,s,mini,maxi};
        }
        return {false,0,0,0};  
    }
    int maxSumBST(TreeNode* root) {
        ans=0;
        dfs(root);
        return ans;
    }
};