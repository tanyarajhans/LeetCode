

class Solution {
public:
struct DSU
    {
        vector<int>parent;
        DSU(int n)
        {
            parent.resize(n);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
        int find(int x)
        {
            if(parent[x]!=x)
                parent[x]=find(parent[x]);
            return parent[x];
        }
        void unite(int x,int y)
        {
            parent[y]=x;
        }
    };
    int MST(int n,vector<vector<int>>& edges,int del_edge,int add_edge)
    {
        DSU dsu(n);
        int res=0,m=edges.size();
        if(add_edge!=-1)
        {
            res+=edges[add_edge][2];
            dsu.unite(edges[add_edge][0],edges[add_edge][1]);
        }
        for(int i=0;i<m;i++)
        {
            if(i==del_edge || i==add_edge)
                continue;
            int a=edges[i][0],b=edges[i][1];
            int pa=dsu.find(a),pb=dsu.find(b);
            if(pa!=pb)
            {
                dsu.unite(pa,pb);
                res+=edges[i][2];
            }
        }
        for(int i=0;i<n;i++)  //Check disconnection
        {
            if(dsu.find(i)!=dsu.find(0))
                return INT_MAX;
        }
        return res;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
    {
        int m=edges.size();
        for(int i=0;i<m;i++)
            edges[i].push_back(i);
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
            return a[2]<b[2];
        });
        int original=MST(n,edges,-1,-1);
        
        vector<int>critical,pseudo;
        for(int i=0;i<m;i++)
        {
            int c1=MST(n,edges,i,-1);
            if(c1>original)
                critical.push_back(edges[i][3]);
            else
            {
                int c2=MST(n,edges,-1,i);
                if(c2==original)
                    pseudo.push_back(edges[i][3]);
            }
        }
        return {critical,pseudo};
    }
};