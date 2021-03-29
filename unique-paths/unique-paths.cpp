class Solution {
public:
    int uniquePaths(int m, int n) {
       int t[m][n];
       memset(t,0,sizeof(t));
      for(int i=0;i<n;i++)
       t[m-1][i]=1;
      for(int i=0;i<m;i++)
       t[i][n-1]=1;
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                t[i][j]+=t[i+1][j]+t[i][j+1];
            }
        }
        return t[0][0];
    }
};