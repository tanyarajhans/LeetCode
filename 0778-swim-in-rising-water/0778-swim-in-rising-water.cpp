class Solution {
public:
    bool isSafe(int x, int y, int n){
        if(x>=0 && x<n && y>=0 && y<n){
            return true;
        }
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> visited(n*n, false); 
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> q;
        
        q.push({grid[0][0], {0,0}});
        visited[grid[0][0]] = true;
        int ans = 0;
        
        while(!q.empty()){
            auto temp = q.top();
            q.pop();
            
            ans = max(ans, temp.first);
            
            int x = temp.second.first;
            int y = temp.second.second;
            
            if(x==n-1 && y==n-1){
                return ans;
            }
            
            if(isSafe(x+1,y,n) && visited[grid[x+1][y]]==false){
                visited[grid[x+1][y]] = true;
                q.push({grid[x+1][y], {x+1,y}});
            }
            
            if(isSafe(x-1,y,n) && visited[grid[x-1][y]]==false){
                visited[grid[x-1][y]] = true;
                q.push({grid[x-1][y], {x-1,y}});
            }
            
            if(isSafe(x,y+1,n) && visited[grid[x][y+1]]==false){
                visited[grid[x][y+1]] = true;
                q.push({grid[x][y+1], {x,y+1}});
            }
            
            if(isSafe(x,y-1,n) && visited[grid[x][y-1]]==false){
                visited[grid[x][y-1]] = true;
                q.push({grid[x][y-1], {x,y-1}});
            }
        }
        
        return ans;
    }
};