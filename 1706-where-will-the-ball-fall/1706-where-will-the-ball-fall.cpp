class Solution {
public:
    int n,m;
    
    int solve(vector<vector<int>>& grid, int i, int j){
        if(i>=n)
            return j;
        
        if(grid[i][j]==1){
            if(j==m-1 || grid[i][j+1]==-1)
                return -1;
           
            if(grid[i][j+1]==1)
                return solve(grid,i+1,j+1);
        }
        
        if(grid[i][j]==-1){
            if(j==0 || grid[i][j-1]==1)
                return -1;
            
            if(grid[i][j-1]==-1)
                return solve(grid,i+1,j-1);
        }
        
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        
        vector<int> ans;
        
        for(int i=0;i<m;i++){
            int x=solve(grid,0,i);
            ans.push_back(x);
        }
        
        return ans;
    }
};