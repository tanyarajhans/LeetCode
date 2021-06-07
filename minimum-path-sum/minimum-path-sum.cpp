class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int t[n][m];
        memset(t,0,sizeof(t));
        t[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            t[i][0]=t[i-1][0]+grid[i][0];
        }
        for(int i=1;i<m;i++){
            t[0][i]=t[0][i-1]+grid[0][i];
        }
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                t[i][j]=min(t[i-1][j], t[i][j-1])+grid[i][j];
            }
        }
        return t[n-1][m-1];
    }
};