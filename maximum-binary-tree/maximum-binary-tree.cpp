/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    int index(vector<int>& nums, int l, int r){
        int maxi=INT_MIN,index=-1;
        for(int i=l;i<r;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                index=i;
            }
        }
        return index;
    }
    
    
    TreeNode* tree(vector<int>& nums, int l, int r){
        if(l==r)
            return NULL;
        int ind=index(nums, l, r);
        TreeNode* root = new TreeNode(nums[ind]);
        root->left=tree(nums,l,ind);
        root->right=tree(nums,ind+1,r);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return tree(nums,0,nums.size());
    }
};
