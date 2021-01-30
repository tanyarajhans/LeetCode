class Solution {
public:
    
    void dfs(int i, int n, vector<int> &vis, vector<int> adj[n]){
        vis[i]=1;
        for(auto u : adj[i]){
            if(!vis[u])
                dfs(u,n,vis,adj);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);    
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, n, vis, adj);
                c++;
            }
        }
        int edges=connections.size();
        int ans=edges+c-n;
        if(edges<n-1 || ans<c-1)
            return -1;
        else 
            return c-1;
    }
};