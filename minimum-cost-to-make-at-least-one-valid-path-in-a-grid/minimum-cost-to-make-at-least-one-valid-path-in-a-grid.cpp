class Solution {
public:
    int dis[102][102];
    int minCost(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
        for(int i = 0; i < 102; i++) {
            for(int j = 0; j < 102; j++) {
                dis[i][j] = 1e9;
            }
        }
        dis[0][0] = 0;
        pq.push({ 0, 0, 0 });
        while(!pq.empty()) {
            vector<int> cur = pq.top();
            int x = cur[1], y = cur[2], cst = cur[0];
            pq.pop();
            if(x == grid.size() - 1 && y == grid[0].size()) {
                return cst;
            }
            if(x + 1 < grid.size()) {
                int ncst = grid[x][y] == 3 ? cst : cst + 1;
                if(ncst < dis[x + 1][y]) {
                    dis[x + 1][y] = ncst;
                    pq.push({ ncst, x + 1, y });
                }
            }
            if(y + 1 < grid[0].size()) {
                int ncst = grid[x][y] == 1 ? cst : cst + 1;
                if(ncst < dis[x][y + 1]) {
                    dis[x][y + 1] = ncst;
                    pq.push({ ncst, x, y + 1 });
                }
            }
            if(x - 1 >= 0) {
                int ncst = grid[x][y] == 4 ? cst : cst + 1;
                if(ncst < dis[x - 1][y]) {
                    dis[x - 1][y] = ncst;
                    pq.push({ ncst, x - 1, y });
                }
            }
            if(y - 1 >= 0) {
                int ncst = grid[x][y] == 2 ? cst : cst + 1;
                if(ncst < dis[x][y - 1]) {
                    dis[x][y - 1] = ncst;
                    pq.push({ ncst, x, y - 1 });
                }
            }
        }
        return dis[grid.size() - 1][grid[0].size() - 1];
    }
};