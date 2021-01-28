class Solution {
public:
    int vis[202];
    
    void dfs(int i, vector<vector<int>>& adj){
        vis[i]=1;
        for(int j=0;j<adj.size();j++){
            if(adj[i][j]==1 && vis[j]==0){
               dfs(j, adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
       int c=0;
       memset(vis,0,sizeof(vis));
       for(int i=0;i<isConnected.size();i++){
           if(vis[i]==0){
               dfs(i, isConnected);
               c++;
           }
       }
        return c;
    }
};