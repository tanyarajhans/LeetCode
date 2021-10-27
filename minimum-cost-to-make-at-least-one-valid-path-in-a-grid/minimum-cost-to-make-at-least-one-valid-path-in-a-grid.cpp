class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, m+n));
        dp[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0, 0, 0});
        
        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            int r = v[1], c = v[2];

            for(int k=0; k<4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];
                int cost = 1;
                if(k+1 == grid[r][c]) cost = 0;
                if(nr >= 0 && nc >=0 && nr < m && nc < n && cost + v[0] < dp[nr][nc]) {
                    dp[nr][nc] = cost + v[0];
                    pq.push({dp[nr][nc], nr, nc});
                }    
            }
        }
            
        return dp[m-1][n-1];
    }
};