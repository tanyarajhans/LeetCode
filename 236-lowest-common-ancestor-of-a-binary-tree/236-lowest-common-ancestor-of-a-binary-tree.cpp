/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        if(root==NULL)
            return NULL;
        stack<TreeNode*> st;
        map<TreeNode*, TreeNode*> par;
        par[root]=NULL;
        st.push(root);
        while(par.count(p)==0 || par.count(q)==0){
            TreeNode* curr=st.top();
            st.pop();
            if(curr->left){
                par[curr->left]=curr;
                st.push(curr->left);
            }
            if(curr->right){
                par[curr->right]=curr;
                st.push(curr->right);
            }
        }
        set<TreeNode*> anc;
        while(p){
            anc.insert(p);
            p=par[p];
        }
        while(anc.count(q)==0){
            q=par[q];
        }
        return q;
    }
};