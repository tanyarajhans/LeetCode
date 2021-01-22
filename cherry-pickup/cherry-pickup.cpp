class Solution {
public:
    int t[51][51][51];
    vector<vector<int>> g;
    
    int solve(int r1, int c1, int c2, int n){
        int r2=r1+c1-c2;
        if(r1>=n || r2>=n || c1>=n || c2>=n || g[r1][c1]==-1 || g[r2][c2]==-1)
            return INT_MIN;
        if(t[r1][c1][c2]!=-1)
            return t[r1][c1][c2];
        if(r1==n-1 && c1==n-1)
            return g[r1][c1];
        int ans=g[r1][c1];
        if(c1!=c2)
            ans+=g[r2][c2];
        ans+=max(max(solve(r1,c1+1,c2+1,n), solve(r1+1,c1,c2+1,n)), max(solve(r1,c1+1,c2,n), solve(r1+1,c1,c2,n)));
        return t[r1][c1][c2]=ans;
        
    }
    
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        g=grid;
        memset(t,-1,sizeof(t));
        return max(0,solve(0,0,0,n));
    }
};
