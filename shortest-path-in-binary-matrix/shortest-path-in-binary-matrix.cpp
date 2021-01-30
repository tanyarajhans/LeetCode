class Solution {
public:
    int dx[8] = {0,0,1,-1,1,1,-1,-1};
    int dy[8] = {1,-1,0,0,1,-1,-1,1};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0)
            return -1;
        int ans=0;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int k=q.size();
            ans++;
            while(k--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1 && y==m-1)
                   return ans;
                for(int i=0;i<8;i++){
                   int xx=x+dx[i];
                   int yy=y+dy[i];
                    if(xx>=0 && yy>=0 && xx<n && yy<m && grid[xx][yy]==0){
                        q.push({xx,yy});
                        grid[x][y]=1;
                        grid[xx][yy]=1;
                    }
               }
            }
        }
        return (grid[n-1][m-1]==1)?ans:-1;  
    }
};