class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1)
            return 0;
        int target = (1<<n)-1;
        queue<pair<int, int>> q; //id, mask
        int vis[n][target+1];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            q.push({i, 1<<i});
            vis[i][1<<i]=1;
        }
        int ans=0;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                auto curr=q.front();
                q.pop();
                int id=curr.first;
                int state=curr.second;
                for(auto x: graph[id]){
                    int newState = state | (1<<x);
                    if(newState==target)
                        return ans+1;
                    else if(vis[x][newState]==1)
                    continue;
                    vis[x][newState]=1;
                    q.push({x, newState});
                }
            }
            ans++;
        }
        return -1;
    }
};