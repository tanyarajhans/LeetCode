class Solution {
public:
    vector<int> ans;
    vector<int> count;
    vector<int> adj[30005];
    int N;
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        N=n;
        for(int i=0;i<n;i++){
            ans.push_back(0);
            count.push_back(1);
        }
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        postOrder(0,-1);
        preOrder(0,-1);
        return ans;
    }
    
    void postOrder(int v, int p){
        for(auto u: adj[v]){
            if(u==p)
                continue;
            postOrder(u,v);
            count[v]+=count[u];
            ans[v]+=ans[u]+count[u];
        }
    }
    
    void preOrder(int v, int p){
        for(auto u: adj[v]){
            if(u==p)
                continue;
            ans[u]=ans[v]-count[u]+N-count[u];
            preOrder(u, v);
        }
    }
};