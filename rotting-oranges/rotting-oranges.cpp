class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    c++;
                else if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int ans=0;
        while(!q.empty() && c>0){
            int k=q.size();
            ans++;
            while(k--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int xx=x+dx[i];
                    int yy=y+dy[i];
                    if(xx>=0 && yy>=0 && xx<n && yy<m && grid[xx][yy]==1){
                        c--;
                        grid[xx][yy]=2;
                        q.push({xx,yy});
                    }
                }
            }
        }
        if(c==0)
        return ans;
        return -1;
    }
};