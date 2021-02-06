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
        size_t ans=1;
        queue<pair<TreeNode*, unsigned int>> q;
        q.push({root,0});
        while(!q.empty()){
            if(ans<static_cast<int>(q.back().second-q.front().second+1))
                ans=q.back().second-q.front().second+1;
            int k=q.size();
            while(k--){
                TreeNode* curr=q.front().first;
                unsigned int curx=q.front().second;
                q.pop();
                if(curr->left)
    				q.push({curr->left, curx*2});
    			if(curr->right)
    				q.push({curr->right, curx*2+1});
            }
        }
        return ans;
    }
};