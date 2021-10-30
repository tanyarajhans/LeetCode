class Solution {
public:
    
    bool dfs(int c, int pre, vector<int> adj[], vector<int> &vis){
        vis[c]=1;
        for(auto x: adj[c]){
            if(x==pre)
                 return true;
            else if(!vis[x] &&dfs(x, pre, adj, vis))
                 return true;
        }
        return false;
    }
             
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> adj[n];
        vector<bool> ans;
        for(vector<int> x: prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n, 0);
        for(vector<int> q: queries){
            int pre=q[0];
            int c=q[1];
            for(int i=0;i<n;i++)
                vis[i]=0;
            if(dfs(c, pre, adj, vis))
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};