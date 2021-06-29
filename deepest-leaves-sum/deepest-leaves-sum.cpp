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
    int deepestLeavesSum(TreeNode* root) {
      int s=0;
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            s=0;
            while(k--){
                TreeNode* curr=q.front();
                q.pop();
                s+=curr->val;
                if(curr->left)
                   q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return s;
    }
};