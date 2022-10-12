class Solution {
public:
    vector<int> adj[2001];
    int in[2001];
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        queue<int> q;
        for(auto &x: pre){
            adj[x[1]].push_back(x[0]);
            in[x[0]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(in[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            for(auto &u: adj[curr]){
                in[u]--;
                if(in[u]==0)
                {
                    q.push(u);
                }
            }
        }
        if(ans.size()==n)
            return ans;
        return {};
    }
};