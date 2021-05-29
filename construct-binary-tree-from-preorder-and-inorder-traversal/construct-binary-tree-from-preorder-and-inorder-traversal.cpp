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
    
    TreeNode* solve(vector<int>& pre, vector<int>& in, int p, int s, int e){
        if(p>=pre.size() || s>e)
            return NULL;
        TreeNode* root= new TreeNode(pre[p]);
        int ind;
        for(int i=s;i<=e;i++){
            if(in[i]==pre[p]){
                ind=i;
                break;
            }
        }
        root->left=solve(pre,in,p+1,s,ind-1);
        root->right=solve(pre,in,p+ind-s+1,ind+1,e);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return solve(pre,in,0,0,pre.size()-1);
    }
};