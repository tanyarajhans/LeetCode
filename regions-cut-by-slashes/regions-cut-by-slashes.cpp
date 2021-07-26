

// idea is to split each single square into 4 squares and every subsquare into 4 triangles

class Solution {
public:
    int par[4*30*30];
    
int find(int u){
    if(u == par[u])
        return u;
    
    else
        return par[u]=find(par[u]);
}

void combine (int u, int v){
    u = find(u);
    v = find(v);
    
    if(u == v)
        return;
    
    par[u]=v;
    
    
}
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        for(int i=0;i<4*n*n;i++){
            par[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char c=grid[i][j];
                int root=4*(i*n+j);
                if(c!='\\'){
                    combine(root+0,root+1);
                    combine(root+2,root+3);
                }
                if(c!='/'){
                    combine(root+0,root+2);
                    combine(root+1,root+3);
                }
                //down
                if(i+1<n){
                    combine(root+3, root+(4*n)+0);
                }
                //up
                if(i-1>=0){
                    combine(root, root-(4*n)+3);
                }
                //right
                if(j+1<n){
                    combine(root+2, root+4+1);
                }
                //left
                if(j-1>=0){
                    combine(root+1, root-4+2);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n*n*4;i++){
            if(i==find(i))
                ans++;
        }
        return ans;
    }
};