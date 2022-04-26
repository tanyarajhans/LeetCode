class Solution {
public:
    
    int p[1001];
    vector<pair<int, pair<int,int>>> adj; //cost,i,j
    
    int find(int x){
        if(p[x]==x)
            return x;
        return p[x]=find(p[x]);
    }
    
    void merge(int x, int y){
        p[x]=y;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj.push_back({d,{i,j}});
            }
        }
        for(int i=0;i<n;i++)
            p[i]=i;
        sort(adj.begin(), adj.end());
        int s=0;
        int k=adj.size();
        for(int i=0;i<k;i++){
            int u=find(adj[i].second.first);
            int v=find(adj[i].second.second);
            if(u!=v){
                s+=adj[i].first;
                merge(u,v);
            }
        }
        return s;
    }
};