class Solution {
public:
    int n,m;
    int vis[17][17];
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=n || j>=m)
            return 0;
        if(grid[i][j]==0 || vis[i][j])
            return 0;
        int ans=0;
        ans+=grid[i][j];
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int xx=i+dx[k];
            int yy=j+dy[k];
            int c=solve(xx,yy,grid);
            ans=max(grid[i][j]+c, ans);
        }
        vis[i][j]=0;
        return ans;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0)
                    ans=max(ans, solve(i,j,grid));
            }
        }
        return ans;
    }
};