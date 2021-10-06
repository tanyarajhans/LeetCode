/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        queue<TreeNode*> q;
        if(root==NULL){
            s="null";
            return s;
        }
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            while(k--){
                TreeNode* curr=q.front();
                q.pop();
                if(!curr)
                    s+="null,";
                else{
                    s+=to_string(curr->val);
                    s+=",";
                    q.push(curr->left);
                    q.push(curr->right);
                }  
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="null")
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            getline(s, str, ',');
            if(str=="null")
                curr->left=NULL;
            else{
                curr->left=new TreeNode(stoi(str));
                q.push(curr->left);
            }
            getline(s, str, ',');
            if(str=="null")
                curr->right=NULL;
            else{
                curr->right=new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));