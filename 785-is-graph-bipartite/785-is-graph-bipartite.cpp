class Solution {
public:
    int col[102];
    int n;
    
    bool dfs(int v,vector<vector<int>>& graph){
        col[v]=1;
       // vis[v]=1;
        queue<int> q;
        q.push(v);
        while(!q.empty()){
            int k=q.front();
            q.pop();
            for(auto u: graph[k]){
                if(col[u]==-1){
                    col[u]=1-col[k];
                   // vis[u]=1;
                    q.push(u);
                }
                else if(col[u]==col[k])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n=graph.size();
        for(int i=0;i<n;i++){
            col[i]=-1;
        }
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!dfs(i,graph))
                    return false;
            }
        }
        return true;
    }
};