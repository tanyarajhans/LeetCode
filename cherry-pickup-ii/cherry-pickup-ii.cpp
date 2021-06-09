class Solution {
public:
    int t[72][72][72]; 
    int n,m;
    
    int solve(vector<vector<int>>& grid, int row, int col1, int col2){
        if(col1<0 || col2<0 || col1>=m || col2>=m || row<0 || row>=n)
            return 0;
        if(t[row][col1][col2]!=-1)
            return t[row][col1][col2];
        int ans=0;
        ans+=grid[row][col1];
        if(col1!=col2)
            ans+=grid[row][col2];
        if(row!=n-1){
            int maxi=0;
            for(int c1=col1-1;c1<=col1+1;c1++){
                for(int c2=col2-1;c2<=col2+1;c2++){
                    maxi=max(maxi, solve(grid, row+1, c1, c2));
                }
            }
            ans+=maxi;
        }
        return t[row][col1][col2]=ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        //row, col1, col2 (row,col1)-> 1st robot and (row,col1)-> 2nd robot
        memset(t,-1, sizeof(t));
        return solve(grid, 0, 0, m-1);
    }
};