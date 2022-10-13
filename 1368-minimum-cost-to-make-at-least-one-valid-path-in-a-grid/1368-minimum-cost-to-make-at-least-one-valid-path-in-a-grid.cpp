class Solution {
public:
    int dx[4]={0,0,1,-1};//acc to no assigned to directions
    int dy[4]={1,-1,0,0};
    
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=n+m;
            }
        }
        dp[0][0]=0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            int d=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            pq.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy=y+dy[i];
                int cost=1;
                if(grid[x][y]==i+1)
                    cost=0;
                if(xx>=0 && yy>=0 && xx<n && yy<m){
                    if(dp[xx][yy]>dp[x][y]+cost){
                        dp[xx][yy]=dp[x][y]+cost;
                        pq.push({dp[xx][yy],xx,yy});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};