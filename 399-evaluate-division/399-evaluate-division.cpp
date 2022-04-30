class Solution {
public:
    vector<double> ans;
    map<string, vector<pair<string, double>>> m;
    
    void dfs(string a, string b, unordered_map<string, int> &vis, double &x, double val){
        if(vis[a]==1)
            return;
        vis[a]=1;
        if(a==b){
            x=val;
            return;
        }
        for(auto u: m[a]){
            dfs(u.first, b, vis, x, val*u.second);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& que) {
        for(int i=0;i<eq.size();i++){
            m[eq[i][0]].push_back({eq[i][1], values[i]});
            m[eq[i][1]].push_back({eq[i][0], 1/values[i]});
        }
        
        for(int i=0;i<que.size();i++){
            string a=que[i][0];
            string b=que[i][1];
            unordered_map<string, int> vis;
            double x=-1.0;
            if(m.count(a)>0)
            dfs(a,b,vis,x,1.0);
            ans.push_back(x);
        }
        return ans;
    }
};