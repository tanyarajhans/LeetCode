class Solution {
public:
    unordered_map<string, vector<string>> adj;
    
    void dfs(unordered_set<string> &vis, string s, vector<string> &abc){
        if(vis.find(s)!=vis.end())
            return;
        vis.insert(s);
        abc.push_back(s);
        
        for(int i=0;i<adj[s].size();i++){
            dfs(vis, adj[s][i], abc);
        }
        
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> m;
        vector<vector<string>> ans;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
               adj[accounts[i][1]].push_back(accounts[i][j]);
               adj[accounts[i][j]].push_back(accounts[i][1]);
               m[accounts[i][j]]=accounts[i][0];
           }
        }
        unordered_set<string> vis;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(vis.find(accounts[i][j])==vis.end()){
                    vector<string> abc;
                    dfs(vis, accounts[i][j], abc);
                    sort(abc.begin(), abc.end());
                    abc.insert(abc.begin(), m[accounts[i][j]]);
                    ans.push_back(abc);
                }
            }
        }
        return ans;
    }
};