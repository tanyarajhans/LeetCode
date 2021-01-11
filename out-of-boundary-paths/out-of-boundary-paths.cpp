class Solution {
public:
    long long int mod=1000000007;
    int t[51][51][52];
    
    int solve(int m, int n, int N, int i, int j){
        if(i<0 || j<0 || i>=m || j>=n)
            return 1;
        if(N<=0)
            return 0;
        if(t[i][j][N]!=-1)
            return t[i][j][N];
        int l=solve(m,n,N-1,i,j-1);
        int r=solve(m,n,N-1,i,j+1);
        int u=solve(m,n,N-1,i-1,j);
        int d=solve(m,n,N-1,i+1,j);
        
        return t[i][j][N]=((l+r)%mod+(u+d)%mod)%mod;
        
    }
    
    
    int findPaths(int m, int n, int N, int i, int j) {
        memset(t,-1,sizeof(t));
        return solve(m,n,N,i,j);
        
    }
};
