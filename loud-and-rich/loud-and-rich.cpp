class Solution {
public:
    vector<int> adj[502];
    vector<int> ans;
    
    int dfs(int v, vector<int>& quiet){
        int mini=v;
        for(auto rich: adj[v]){
            if(ans[rich]==-1){
                int someoneElse=dfs(rich, quiet);
                if(quiet[someoneElse]<quiet[mini])
                    mini=someoneElse;
            } 
            else{
                if(quiet[ans[rich]]<quiet[mini])
                    mini=ans[rich];
            }
        }
        ans[v]=mini;
        return mini;
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=richer.size();
        int k=quiet.size();
        ans.resize(k, -1);
        for(int i=0;i<n;i++){
            adj[richer[i][1]].push_back(richer[i][0]);
        }
        for(int i=0;i<k;i++){
            if(ans[i]==-1)
               dfs(i, quiet);
        }
        return ans;
    }
};