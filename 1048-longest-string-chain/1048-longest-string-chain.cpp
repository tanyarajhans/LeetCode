class Solution {
public:
    vector<int> adj[1001];
    int vis[10001];
    
    static bool comp(string a, string b){
        if(a.size()!=b.size())
        return a.size()<b.size();
        return a<b;
    }
    
    bool isPossible(string a, string b){
        int ind=-1;
        int c=0;
        int n=b.size();
        for(int j=0;j<n;j++){
            if(a[j]!=b[j]){
                ind=j;
                break;
            }
        }
        if(ind==n-1){
            if(n>1)
                return true;
            else
                return false;
        }
            
        for(int j=ind+1;j<n;j++){
            if(a[j-1]!=b[j])
                return false;
        }
        return true;
    }
    
    int dfs(int i){
        if(vis[i])
            return 0;
        int c=1;
        vis[i]=1;
        for(auto x: adj[i]){
            if(!vis[x]){
                c=max(c, dfs(x)+1);
            }
            //cout<<x<<" ";
        }
        return c;
    }
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), comp);
        for(int i=0;i<n;i++){
            string s1=words[i];
            int v=s1.size();
            for(int j=i+1;j<n;j++){
                string s2=words[j];
                int w=s2.size();
                if(w!=v+1)
                    continue;
                if(isPossible(s1, s2))
                {
                    adj[i].push_back(j);
                }
            }
        }
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<n;i++){
            memset(vis,0,sizeof(vis));
            ans=max(ans, dfs(i));
            cout<<endl;
        }
        for(auto x: adj[3])
            cout<<x;
        return ans;
    }
};