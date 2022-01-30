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
    vector<int> ans;
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        while(root1 || root2 || !s1.empty() || !s2.empty()){
            while(root1!=NULL){
                s1.push(root1);
                root1=root1->left;
            }
            while(root2!=NULL){
                s2.push(root2);
                root2=root2->left;
            }
            if(s2.empty() || (!s1.empty() && s1.top()->val<=s2.top()->val)){
                root1=s1.top();
                s1.pop();
                ans.push_back(root1->val);
                root1=root1->right;
            }
            else{
                root2=s2.top();
                s2.pop();
                ans.push_back(root2->val);
                root2=root2->right;
            }
        }
        return ans;
    }
};