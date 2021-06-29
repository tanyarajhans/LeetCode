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
    
    unordered_map<TreeNode*, TreeNode*> m;
    vector<int> ans;
    
    void findParent(TreeNode* root){
        if(root==NULL)
            return;
        if(root->left)
        m[root->left]=root;
        if(root->right)
        m[root->right]=root;
        
        findParent(root->left);
        findParent(root->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL)
            return ans;
        
        findParent(root);
        unordered_set<TreeNode*> vis;
        
        queue<TreeNode*> q;
        q.push(target);
        while(!q.empty()){
            int n=q.size();
            while(n--){
            TreeNode* curr=q.front();
            q.pop();
            vis.insert(curr);
            if(k==0){
                ans.push_back(curr->val);
            }
            if(m.count(curr)>0 && vis.count(m[curr])==0){
                q.push(m[curr]);
            }
            if(curr->left && vis.count(curr->left)==0){
                q.push(curr->left);
            }
            if(curr->right && vis.count(curr->right)==0){
                q.push(curr->right);
            }
          }
          k--;
          if(k<0)
            break;
        }
        return ans;
    }
};