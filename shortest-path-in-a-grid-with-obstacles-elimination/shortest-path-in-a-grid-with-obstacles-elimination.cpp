#define MAX 299999999

class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
	int shortestPath(vector<vector<int>>& grid, int k) {
		int m = grid.size();
        int n = grid[0].size();
        //Following 2 lines improves performance from ~50% to ~98%.. When the same is incorporated in the main loop it will be ~100%
        int minSteps = m + n -2;
        if (k >= minSteps) 
            return minSteps;

		queue<vector<int>> q;
		int step = 0;
		vector<vector<int>> visited(m, vector<int>(n, k+1));
		q.push({0, 0, 0});
		visited[0][0]= 0;

		while (!q.empty()) { 
			int l = q.size();
			for (int i = 0; i < l; i++) { 
				vector<int> s = q.front();
				q.pop();
				if (s[2] == k + 1) { 
					continue;
				}

				if (s[0] == m - 1 && s[1] == n - 1) { 
					return step;
				}
                
				for (vector<int>& dir : dirs) { 
					int new_x = s[0] + dir[0];
					int new_y = s[1] + dir[1];
					//Note: validity, visited
					if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) { 
                       if (visited[new_x][new_y] <= s[2] + grid[new_x][new_y]) continue; // came here with less obstancles removed.
                        visited[new_x][new_y] = s[2] +  grid[new_x][new_y];
 						q.push({new_x, new_y, s[2] +  grid[new_x][new_y]});

					}
				}
			}
			step++;
		}
		return -1;
    }
};