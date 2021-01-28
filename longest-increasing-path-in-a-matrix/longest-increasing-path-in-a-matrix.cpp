class Solution {
public:
    int n,m;
    int solve(int i, int j, vector<vector<int>> &t, vector<vector<int>>& mat){
        if(t[i][j]!=-1)
            return t[i][j];
        int a=1,b=1,c=1,d=1;
        if(i+1<n && mat[i][j]<mat[i+1][j])
            a+=solve(i+1,j,t,mat);
        if(j+1<m && mat[i][j]<mat[i][j+1])
            b+=solve(i,j+1,t,mat);
        if(i-1>=0 && mat[i][j]<mat[i-1][j])
            c+=solve(i-1,j,t,mat);
        if(j-1>=0 && mat[i][j]<mat[i][j-1])
            d+=solve(i,j-1,t,mat);
        return t[i][j]=max(max(a,b),max(c,d));
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        vector<vector<int>> t;
        t.resize(n, vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans, solve(i,j,t,matrix));
            }
        }
        return ans;
    }
};