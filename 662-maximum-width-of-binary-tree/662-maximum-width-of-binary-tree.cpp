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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 1;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int k=q.size();
            int start=q.front().second;
            int end=q.back().second;
            ans=max(ans, end-start+1);
            while(k--){
                auto curr=q.front();
                q.pop();
                int ind=curr.second-start;
                if(curr.first->left){
                        q.push({curr.first->left, (long long)2*ind+1});
                }
                if(curr.first->right){
                        q.push({curr.first->right, (long long)2*ind+2});
                }
            }
        }
        return ans;
    }
};