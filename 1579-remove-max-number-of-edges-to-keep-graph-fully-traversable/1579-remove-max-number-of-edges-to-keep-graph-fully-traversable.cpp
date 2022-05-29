class Solution {
public:
    
    vector<int> par;
    
    int find(int x){
        if(par[x]==x)
            return x;
        return par[x]=find(par[x]);
    }
    
    void merge(int x, int y){
        int a=find(x);
        int b=find(y);
        par[a]=b;
    }
    
    int isValid(int type, vector<vector<int>>& edges){
        int c=0;
        int m=edges.size();
        for(int i=0;i<m;i++){
            if(edges[i][0]==type && find(edges[i][1])!=find(edges[i][2])){
                c++;
                merge(edges[i][1], edges[i][2]);
            }
        }
        return c;
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        for(int i=0;i<=n;i++){
            par.push_back(i);
        }
        int t3=isValid(3, edges);
        vector<int> p=par;
        int t1=isValid(1, edges);
        par=p;
        int t2=isValid(2, edges);
        if(t1+t3!=n-1 || t2+t3!=n-1)
            return -1;
        return m-t1-t2-t3;
    }
};