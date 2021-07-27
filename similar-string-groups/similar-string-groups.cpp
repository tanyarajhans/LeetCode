class Solution {
public:
    set<string> s1;
    vector<string> v;
    vector<int> adj[305];
    int vis[305];
    
    void dfs(int v){
        vis[v]=1;
        for(auto u: adj[v]){
            if(!vis[u])
                dfs(u);
        }
    }
    
    bool similar(string s, string t){
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                c++;
                if(c>2)
                  return false;
            }
        }
        return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        for(int i=0;i<strs.size();i++)
            s1.insert(strs[i]);
        for(auto it:s1){
            v.push_back(it);
        }
        int n=v.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(similar(v[i],v[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
                ans++;
            }
        }
        return ans;
    }
};