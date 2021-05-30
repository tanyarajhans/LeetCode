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
    map<int, vector<pair<int, int>>> m;
    vector<vector<int>> ans;
    
    void dfs(TreeNode* root, int x, int y){
        if(root==NULL)
            return;
        m[x].push_back({y, root->val});
        if(root->left)
            dfs(root->left, x-1, y+1);
        if(root->right)
            dfs(root->right, x+1, y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        map<int, vector<pair<int, int>>>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            sort(it->second.begin(), it->second.end());
            vector<int> v;
            for(auto u: it->second){
                v.push_back(u.second);
            }
            ans.push_back(v);
        }
        return ans;
    }
};