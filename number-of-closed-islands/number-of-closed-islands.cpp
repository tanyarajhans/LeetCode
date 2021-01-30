class Solution {
public:
    
    bool dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(grid[i][j]==1 || grid[i][j]==-1)
            return true;
        if(i==0 || j==0 || i==grid.size()-1 || j==grid[i].size()-1)
            return false;
        grid[i][j]=-1;
        bool l=dfs(i,j-1,grid);
        bool r=dfs(i,j+1,grid);
        bool u=dfs(i-1,j,grid);
        bool d=dfs(i+1,j,grid);
        return l && r && u && d;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0 && dfs(i,j,grid))
                    c++;
            }
        }
        return c;
    }
};