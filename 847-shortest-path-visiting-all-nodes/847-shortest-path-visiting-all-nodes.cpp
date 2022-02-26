class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1)
            return 0;
        int target = (1<<n)-1;
        queue<pair<int,pair<int, int>>> q; //id, dist, mask
        int ans=0;
        int vis[n][target+1];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            q.push({i, {0, 1<<i}});
            vis[i][1<<i]=1;
        }
        
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int id=curr.first;
            int dist=curr.second.first;
            int state=curr.second.second;
            for(auto x: graph[id]){
                int newState = state | (1<<x);
                if(newState==target)
                    return dist+1;
                else if(vis[x][newState]==1)
                    continue;
                vis[x][newState]=1;
                q.push({x, {dist+1,newState}});
            }
        }
        return -1;
    }
};