class Solution {
public:
    int n,m;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=n || j>=m)
            return 0;
        if(grid[i][j]==0)
            return 0;
        int ans=0;
        int temp=grid[i][j];
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int xx=i+dx[k];
            int yy=j+dy[k];
            int c=solve(xx,yy,grid);
            ans=max(c, ans);
        }
        grid[i][j]=temp;
        return ans+temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0)
                    ans=max(ans, solve(i,j,grid));
            }
        }
        return ans;
    }
};