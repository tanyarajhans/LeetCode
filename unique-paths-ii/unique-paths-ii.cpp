class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        
        int t[n][m];
        memset(t,0,sizeof(t));
        
        if(obstacleGrid[0][0]==1)
            return 0;
        
         for(int i=0;i<m;i++){
            if(obstacleGrid[0][i]==0)
                t[0][i]=1;
            else break;
        }
        
        for(int i=0;i<n;i++){
            if(obstacleGrid[i][0]==0)
                t[i][0]=1;
            else break;
        }
        
        
         for(int i=1;i<n;i++){
              for(int j=1;j<m;j++){
                if(obstacleGrid[i][j]==0){
                    t[i][j]=t[i-1][j]+t[i][j-1];
                }
                  else t[i][j]=0;
              }
         }
         return t[n-1][m-1];
        
    }
};
