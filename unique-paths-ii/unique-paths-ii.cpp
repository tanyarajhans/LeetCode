class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long t[n][m];
        memset(t,0,sizeof(t));
        if(grid[n-1][m-1]==1)
            return 0;
        t[n-1][m-1]=1;
        for(int i=n-2;i>=0;i--){
            if(grid[i][m-1]==0)
                t[i][m-1]=t[i+1][m-1];
            else
                t[i][m-1]=0;
        }
        for(int i=m-2;i>=0;i--){
            if(grid[n-1][i]==0)
                t[n-1][i]=t[n-1][i+1];
            else
                t[n-1][i]=0;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2; j>=0;j--){
                if(grid[i][j]==0)
                    t[i][j]=t[i+1][j]+t[i][j+1];
                else
                    t[i][j]=0;
            }
        }
        return t[0][0];
    }
};