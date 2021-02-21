class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<int> adj[n];
        for(vector<int> e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int> l;
        for(int i=0;i<n;i++){
            if(adj[i].size()==1)
                l.push(i);
        }
        while(n>2){
            int k=l.size();
            n-=k;
            for(int i=0;i<k;i++){
                int curr=l.front();
                l.pop();
                for(auto &p: adj[curr]){
                    auto it=std::find(adj[p].begin(), adj[p].end(), curr);
                    adj[p].erase(it);
                    if(adj[p].size()==1)
                        l.push(p);
                }
            }
        }
        vector<int> ans;
        while(!l.empty()){
            ans.push_back(l.front());
            l.pop();
        }
        return ans;
    }
};