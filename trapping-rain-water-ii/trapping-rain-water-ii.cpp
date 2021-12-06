class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        typedef pair<int,int> cell;
        priority_queue<cell, vector<cell>, greater<cell>> q;
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        vector<int> visited(m*n, false);
        
        for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (i == 0 || i == m-1 || j == 0  || j == n-1) {
                if (!visited[i*n+j])
                    q.push(cell(heightMap[i][j], i*n+j));
                visited[i*n+j] = true;
            }
        }
        
        int dir[4][2] = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 0;
        while(!q.empty()) {
            cell c = q.top();
            q.pop();
            int i = c.second/n, j = c.second%n;
            
            for (int r = 0; r < 4; ++r) {
                int ii = i+dir[r][0], jj = j+dir[r][1];
                if (ii < 0 || ii >= m || jj < 0 || jj >= n || visited[ii*n+jj])
                    continue;
                ans += max(0, c.first - heightMap[ii][jj]);
                q.push(cell(max(c.first, heightMap[ii][jj]), ii*n+jj));
                visited[ii*n+jj] = true;
            }
        }
        return ans;
    }
};