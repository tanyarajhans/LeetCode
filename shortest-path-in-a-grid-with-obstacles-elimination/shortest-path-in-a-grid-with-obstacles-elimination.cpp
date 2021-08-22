#define MAX 299999999

class Solution {
public:
    int n;
    int m;
    long long int dp[42][42][1602];
    
    long long int solve(vector<vector<int>>& grid, int k, int i, int j){
        if(grid[i][j]<0)
            return MAX;
        
        if(i==n-1 && j==m-1)
            return 0;
            
        
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        
        if(grid[i][j]==1){
            k--;
            
            if(k<0)
            return MAX;
        }
             
        int currVal = grid[i][j];
        grid[i][j] = -1;
        
        long long int ans=MAX;
        
        if(i+1<n)
            ans=1+solve(grid, k, i+1, j);
        if(j-1>=0)
            ans=min(ans, 1+solve(grid, k, i, j-1));
        if(j+1<m)
            ans=min(ans, 1+solve(grid, k, i, j+1));
        if(i-1>=0)
            ans=min(ans, 1+solve(grid, k, i-1, j));
        
        
        grid[i][j]=currVal;
        
        return dp[i][j][k]=ans;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        long long int ans=solve(grid, k, 0, 0);
        if(ans>=MAX)
        return -1;
        return ans;
    }
};