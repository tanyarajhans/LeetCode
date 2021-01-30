class Solution {
public:
    vector<int> adj[26];
    int vis[26];
    int col[26];
    
    void dfs(int i, int c){
        vis[i]=1;
        col[i]=c;
        for(int u: adj[i]){
            if(!vis[u])
            dfs(u, c);
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        for(int i=0;i<n;i++){
            if(equations[i][1]=='='){
                char x=equations[i][0];
                char y=equations[i][3];
                adj[x-'a'].push_back(y-'a');
                adj[y-'a'].push_back(x-'a');
            }
        }
        int c=0;
        for(int i=0;i<26;i++){
            if(!vis[i]){
                dfs(i, c);
                c++;
            }
        }
        for(int i=0;i<n;i++){
            if(equations[i][1]=='!'){
                char x=equations[i][0];
                char y=equations[i][3];
                if(col[x-'a']==col[y-'a'])
                    return false;
            }
        }
        return true;
        
    }
};