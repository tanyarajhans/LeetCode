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
    long long int ans=0;
    
    void solve(TreeNode* root, string sum){
        if(root==NULL)
            return;
        sum+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            reverse(sum.begin(), sum.end());
            long long int temp=0;
            long long int c=1;
            for(int i=0;i<sum.size();i++){
                temp+=c*(sum[i]-'0');
                c*=10;
            }
            ans+=temp;
        }
        solve(root->left, sum);
        solve(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        solve(root, "");
        return ans;
    }
};