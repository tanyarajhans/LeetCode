class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> adj[100005];
        for(vector<int> &x: edges){
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=100000;i++){
            if(adj[i].size()==n)
                return i;
        }
        return -1;
    }
};