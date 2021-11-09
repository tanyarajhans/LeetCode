class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> t(n, -1); //time
        queue<int> q;
        q.push(0);
        t[0]=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto u: adj[curr]){
                if(t[u]==-1){
                    t[u]=t[curr]+1;
                    q.push(u);
                }
            }
        }
        int ans=1;
        for(int i=1;i<=n-1;i++){
            int v=(2*t[i]-1)/patience[i];
            int lastSent=v*patience[i];
            int lastIn=lastSent+2*t[i];
            ans=max(ans, lastIn);
        }
        return ans+1;
    }
};