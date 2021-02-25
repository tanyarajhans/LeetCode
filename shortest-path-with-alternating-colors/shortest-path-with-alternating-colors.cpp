class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<red.size();i++){
            adj[red[i][0]].push_back({red[i][1],0});
        }
        for(int i=0;i<blue.size();i++){
            adj[blue[i][0]].push_back({blue[i][1],1});
        }
        vector<vector<int>> vis(n, vector<int>(2, 0));
        queue<pair<int,int>> q;
        vector<int> ans(n,-1);
        int currl=0;
        q.push({0,-1});
        while(!q.empty()){
            int k=q.size();
            for(int i=0;i<k;i++){
                int curr=q.front().second;
                int currn=q.front().first;
                q.pop();
                if(ans[currn]==-1)
                    ans[currn]=currl;
                for(auto u: adj[currn]){
                    if(u.second!=curr && !vis[u.first][u.second]){
                        vis[u.first][u.second]=1;
                        q.push({u});
                    }
                }
            }
            currl++;
        }
        return ans;
    }
};