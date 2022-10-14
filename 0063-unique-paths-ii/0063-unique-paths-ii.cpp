class Solution {
public:
    int n,m;
    int dp[102][102];
    
    int solve(int x, int y, vector<vector<int>>& a){
        if(x<0 || y<0 || x>=n || y>=m || a[x][y]==1)
            return 0;
        if(x==n-1 && y==m-1)
            return 1;
        if(dp[x][y]!=-1)
            return dp[x][y];
        a[x][y]=1;
        int d=solve(x+1,y,a);
        int r=solve(x,y+1,a);
        a[x][y]=0;
        return dp[x][y]=d+r;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        n=a.size();
        m=a[0].size();
        memset(dp,-1,sizeof(dp));
        if(a[n-1][m-1]==1)
            return 0;
        return solve(0,0,a);
    }
};