class Solution {
public:
    int n,m;
    bool ans;
    int dp[101][101][201];
    
    bool solve(int o, int x, int y, vector<vector<char>>& grid){
        if(x>=n || y>=m || x<0 || y<0)
            return false;
        if(grid[x][y]=='(')
            o++;
        else
            o--;
        if(o<0 || o>(m+n)/2)
            return false;
        if(dp[x][y][o]!=-1)
            return dp[x][y][o];
        if(x==n-1 && y==m-1){
            if(o==0){
                return dp[x][y][o]=true;
            }
        }
        return dp[x][y][o]=(solve(o,x+1,y,grid) || solve(o,x,y+1,grid));
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,grid);
    }
};