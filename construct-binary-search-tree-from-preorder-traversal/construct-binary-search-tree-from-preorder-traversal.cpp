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
    int ind=0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int maxi=INT_MAX) {
        if(ind==preorder.size() || preorder[ind]>maxi)
            return NULL;
        int curr=preorder[ind];
        ind++;
        TreeNode* temp=new TreeNode(curr);
        temp->left=bstFromPreorder(preorder, curr);
        temp->right=bstFromPreorder(preorder, maxi);
        return temp;
    }
};