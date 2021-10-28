class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();
       
        deque<pair<int, int>> dq;
        vector<int> dist(m*n, INT_MAX);
        
        int src = 0, des = m*n-1;
        
        dq.push_front({src, 0});
        dist[src] = 0;
                
        while(!dq.empty()) {
            int curr = dq.front().first;
            int dis = dq.front().second;
            
            dq.pop_front();
            
            if(curr == des)
                return dis;
            
            int x = curr/n , y = curr%n;
            
            for(int k=0; k<4; k++) {
                int i = x + dx[k];
                int j = y + dy[k];
                
                int u = i*n + j;
                
                if(i>=0 && j>=0 && i<m && j<n) {
                    int wt = (grid[x][y] != k+1);
                    
                    if(dis + wt < dist[u])
                    {
                        dist[u] = dis + wt;
                        if(wt == 1) 
                            dq.push_back({u, dis + wt});
                        else 
                            dq.push_front({u, dis + wt});
                    }
                }
            }
        }        
        return -1;
    }
};