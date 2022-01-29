class Solution {
public:
    int find(int x,vector<int>&par){
        if(x==par[x]){
            return x;
        }
        int t=find(par[x],par);
        par[x]=t;
        return t;
    }
    bool uni(int x,int y,vector<int>&par,vector<int>&rank){
        int lx=find(x,par);
        int ly=find(y,par);
        if(lx!=ly){
            if(rank[lx]>rank[ly]){
                par[lx]=ly;
            }else if(rank[ly]>rank[lx]){
                par[ly]=lx;
            }else{
                par[lx]=ly;
                rank[ly]++;
            }
            return false;
        }return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> par(edges.size()+1);
        vector<int> rank(edges.size()+1,1);
        for(int i=0;i<par.size();i++){
            par[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            bool f=uni(edges[i][0],edges[i][1],par,rank);
            if(f){
                return edges[i];
            }
        }
        vector<int> v(2);
        return v;
    }
};