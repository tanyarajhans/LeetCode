class Solution {
public:
    int vis[102];
    int col[102];
    
    bool dfs(int v, int c, vector<vector<int>>& graph){
        vis[v]=1;
        col[v]=c;
        for(auto u: graph[v]){
            if(!vis[u]){
                if(!dfs(u, c^1, graph))
                    return false;
            }
            else if(col[u]==col[v])
                    return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        for(int i=0;i<n;i++){
            vis[i]=0;
            col[i]=0;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i, 0, graph)==false)
                    return false;
            }
        }
        return true;
    }
};