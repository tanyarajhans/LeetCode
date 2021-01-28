class Solution {
public:
    
    bool isCyclic(int v, vector<int> &ans, vector<int> &vis, vector<vector<int>> &adj){
        vis[v]=-1;
        for(int u: adj[v]){
            if(vis[u]==-1)
                return true;
            if(vis[u]==0 && isCyclic(u, ans, vis, adj))
                return true;
        }
        vis[v]=1;
        ans.push_back(v);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        vector<int> vis(numCourses,0);
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCyclic(i, ans, vis, adj))
                    return {};
            }
        }
        return ans;
    }
};