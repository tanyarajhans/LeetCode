class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        int ans=0;
        if(q.size()==n*m)
            return -1;
        while(!q.empty()){
            int k=q.size();
            ans++;
            for(int i=0;i<k;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int xx=x+dx[i];
                    int yy=y+dy[i];
                    if(xx>=0 && yy>=0 && xx<n && yy<n && grid[xx][yy]==0){
                        q.push({xx,yy});
                        grid[xx][yy]=1;
                    }
                }
            }
        }
        return ans-1;
    }
};