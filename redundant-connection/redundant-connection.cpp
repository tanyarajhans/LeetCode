class Solution {
public:
    vector<int> adj[1001];
    
    bool dfs(int u, int v, int p){
        if(u==v)
            return true;
        for(int k: adj[u]){
            if(k==p)
                continue;
            if(dfs(k,v,u))
                return true;
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n=edges.size();
        for(vector<int> i: edges){
            int u=i[0];
            int v=i[1];
            if(dfs(u,v,0)){
                ans.push_back(u);
                ans.push_back(v);
            }
            else{
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        return ans;
    }
    
};