class Solution {
public:
    
    void dfs(int v, vector<int> &col, vector<int> adj[]){
        for(int i=1;i<=4;i++){
            bool f=false;
            for(auto x: adj[v]){
                if(col[x]==i){
                    f=true;
                    break;
                }
            }
            if(f==false){
                col[v]=i;
                break;
            }
        }
        for(auto x: adj[v])
            if(col[x]==-1)
               dfs(x, col, adj);
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        for(int i=0;i<paths.size();i++){
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> col(n+1, -1);
        for(int i=1;i<=n;i++){
            if(col[i]==-1){
                dfs(i, col, adj);
            }
        }
        col.erase(col.begin());
        return col;
    }
};