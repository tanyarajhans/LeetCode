class Solution {
public:
    
    int n,m;
    bool vis[302][302];
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i>=n || i<0 || j>=m || j<0 || grid[i][j]!='1' || vis[i][j]==true)
            return;
         vis[i][j]=true;
         dfs(grid, i-1, j);
         dfs(grid, i, j-1);
         dfs(grid, i+1, j);
         dfs(grid, i, j+1);
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(vis,false,sizeof(vis));
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j);
                    c++;
                }
            }
        }
        return c;
    }
};