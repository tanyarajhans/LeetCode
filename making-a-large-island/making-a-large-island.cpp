class Solution {
public:
    int n,m;
    unordered_map<int, int> size;
    int vis[502][502];
    
    int dfs(int i, int j, vector<vector<int>>& grid, int islandNum){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0 || vis[i][j]!=-1){
            return 0;
        }
        vis[i][j]=islandNum;
        int size=1;
        size+=dfs(i+1,j,grid,islandNum);
        size+=dfs(i-1,j,grid,islandNum);
        size+=dfs(i,j+1,grid,islandNum);
        size+=dfs(i,j-1,grid,islandNum);
        return size;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(vis,-1,sizeof(vis));
        int l=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==-1){
                    size[l]=dfs(i, j, grid, l);
                    l++;
                }
            }
        }
        
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int area=1;
                    set<int> s;
                    if(i+1<n) 
                    s.insert(vis[i+1][j]);
                    if(i-1>=0)
                    s.insert(vis[i-1][j]);
                    if(j+1<m) 
                    s.insert(vis[i][j+1]);
                    if(j-1>=0) 
                    s.insert(vis[i][j-1]);
                    for(int c: s){
                        area+=size[c];
                    }
                    maxarea=max(maxarea, area);
                }
            }
        }
        if(maxarea!=0)
        return maxarea;
        return n*m;
    }
};