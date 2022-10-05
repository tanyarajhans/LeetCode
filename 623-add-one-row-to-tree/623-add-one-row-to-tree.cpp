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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)
            return new TreeNode(val);
        if(depth==1){
            TreeNode* ans=new TreeNode(val);
            ans->left=root;
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int l=0;
        while(l<depth-2){
            int k=q.size();
            while(k--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            l++;
        }
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            TreeNode* ans1=new TreeNode(val);
            TreeNode* ans2=new TreeNode(val);
            TreeNode* p=curr->left;
            TreeNode* q=curr->right;
            curr->left=ans1;
            curr->right=ans2;
            ans1->left=p;
            ans2->right=q;
        }
        return root;
    }
};