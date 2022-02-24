class Solution {
public:
    
   vector<int> toposort(vector<int> graph[], vector<int> &in){
        vector<int> ans;
        queue<int> q;
        int n=in.size();
        for(int i=0;i<n;i++){
            if(in[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int k=q.size();
            while(k--){
                int curr=q.front();
                q.pop();
                ans.push_back(curr);
                for(auto &x: graph[curr]){
                    in[x]--;
                    if(in[x]==0)
                        q.push(x);
                }
            }
        }
        if(ans.size()==n)
            return ans;
        return {};
    }
    
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<n;i++){
            if(group[i]==-1)
                group[i]=m++;
        }
        
        vector<int> adjItems[n];
        vector<int> adjGroups[m];
        
        vector<int> inItems(n,0);
        vector<int> inGroups(m,0);
        
        for(int i=0;i<n;i++){
            for(auto &before : beforeItems[i]){
                adjItems[before].push_back(i);
                inItems[i]++;
                if(group[before]!=group[i]){
                    adjGroups[group[before]].push_back(group[i]);
                    inGroups[group[i]]++;
                }
            }
        }
        vector<int> topoItems=toposort(adjItems, inItems);
        vector<int> topoGroups=toposort(adjGroups, inGroups);
        
        if(topoItems.empty() || topoGroups.empty()){
            return {};
        }
        
        vector<int> newGroups[m];
        
        for(auto &x: topoItems){
            newGroups[group[x]].push_back(x);
        }
        
        vector<vector<int>> v;
        
        for(auto &x: topoGroups){
            v.push_back(newGroups[x]);
        }
        
        vector<int> ans;
        
        for(auto &x: v){
            for(auto &u: x){
                ans.push_back(u);
            }
        }
        
        return ans;
    }
};