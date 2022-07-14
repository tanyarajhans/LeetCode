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
    int rootInd=0;
    
    TreeNode* solve(vector<int>& pre, vector<int>& in, int s, int e){
        if(s>e)
            return NULL;
        TreeNode* root=new TreeNode(pre[rootInd]);
        int ind=-1;
        for(int i=0;i<in.size();i++){
            if(in[i]==pre[rootInd]){
                ind=i;
                break;
            }
        }
        rootInd++;
        root->left=solve(pre,in,s,ind-1);
        root->right=solve(pre, in, ind+1, e);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n=in.size();
        return solve(pre, in, 0, n-1);
    }
};