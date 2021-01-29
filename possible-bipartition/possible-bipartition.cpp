class Solution {
public:
    
    bool dfs(int i, vector<int> &vis, vector<int> &color, int c, vector<vector<int>>& g){
        vis[i]=1;
        color[i]=c;
        for(int u : g[i]){
            if(color[i]==color[u])
                return false;
            if(!vis[u] && dfs(u, vis, color, c^1, g)==false)
                return false;
        }
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
       vector<int> vis(N+1, 0);
       vector<int> color(N+1, -1);
       int c=1;
       bool ans=true;
       vector<vector<int>> g(N+1);
       for(vector<int> v: dislikes){
           g[v[0]].push_back(v[1]);
           g[v[1]].push_back(v[0]);
       }
       for(int i=1;i<N+1;i++){
           if(vis[i]==0)
              ans= ans && dfs(i, vis, color, c, g);
       }
       return ans;
    }
};