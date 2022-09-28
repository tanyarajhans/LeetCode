class Solution {
public:
    int n,m;
    
    int dfs(int x, int y, vector<vector<int>>& grid){
        if(x<0 || y<0 || x>=n || y>=m || grid[x][y]!=1)
            return 0;
        grid[x][y]=0;
        int u=dfs(x-1, y, grid);
        int d=dfs(x+1, y, grid);
        int l=dfs(x, y-1, grid);
        int r=dfs(x, y+1, grid);
        return 1+l+u+d+r;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans=max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};