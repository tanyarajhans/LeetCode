class Solution {
public:
    vector<int> adj[2001];
    int col[2001];
    
    // vis[x]=0 is used for node which is not yet visited, vis[x]=1 is used for the node which is visited and currently its child nodes are being visited and vis[x]=2 done when all the child nodes of a node ("id") are visited and the function returns to parent node of node ("id"). So at that time it is marked as 2 because this node does not require any further traversing.
    bool solve(int x){
        if(col[x]==1)
            return true;
        if(col[x]==0){
            col[x]=1;
            for(auto &u: adj[x]){
                if(solve(u))
                    return true;
            }
        }
        col[x]=2;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        for(auto &x: pre){
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++){
            col[i]=0;
        }
        for(int i=0;i<n;i++){
            if(solve(i))
                return false;
        }
        return true;
    }
};