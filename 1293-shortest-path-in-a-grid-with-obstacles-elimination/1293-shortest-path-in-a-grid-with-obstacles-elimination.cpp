class Solution {
public:
    int n,m;
    int vis[43][43][43*43];
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        memset(vis,0,sizeof(vis));
        queue<vector<int>> q;
        q.push({0,0,k});
        int ans=0;
        while(!q.empty()){
            int l=q.size();
            while(l--){
                auto curr=q.front();
                q.pop();
                int x=curr[0];
                int y=curr[1];
                int obs=curr[2];
                if(x==n-1 && y==m-1){
                    return ans;
                }
                for(int i=0;i<4;i++){
                    int xx=x+dx[i];
                    int yy=y+dy[i];
                    if(xx<0 || yy<0 || xx>=n || yy>=m)
                        continue;
                    if(grid[xx][yy]==0 && !vis[xx][yy][obs]){
                        q.push({xx,yy,obs});
                        vis[xx][yy][obs]=1;
                    }
                    else if(grid[xx][yy]==1 && obs>0 && !vis[xx][yy][obs-1]){
                        q.push({xx,yy,obs-1});
                        vis[xx][yy][obs-1]=1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};