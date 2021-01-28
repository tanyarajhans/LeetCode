class Solution {
public:
    
    void dfs(unordered_map<string, vector<pair<string, double>>> &m, string a, string b, unordered_map<string, int> &vis, double &x, double t){
        if(vis.count(a)>0)
            return;
        vis[a]=1;
        if(a==b){
            x=t;
            return;
        }
        for(auto k: m[a]){
            dfs(m, k.first, b, vis, x, t*k.second);
        }
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> m;
        for(int i=0;i<equations.size();i++){
            m[equations[i][0]].push_back({equations[i][1], values[i]});
            m[equations[i][1]].push_back({equations[i][0], (1/values[i])});
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            string a=queries[i][0];
            string b=queries[i][1];
            double x=-1;
            unordered_map<string, int> vis;
            if(m.count(a)>0)
                dfs(m, a, b, vis, x, 1.0);
            ans.push_back(x);
        }
        return ans;
    }
};