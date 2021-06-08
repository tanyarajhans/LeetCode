class Solution {
public:
    int numSquares(int n) {
        int q=sqrt(n);
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
       // for(int i=0;i<=q;i++)
         //   dp[i*i]=1;
        for(int i=1;i<=n;i++){
            int mini=INT_MAX;
            for(int j=1;j*j<=i;j++){
                mini=min(mini, dp[i-j*j]);
            }
            dp[i]=mini+1;
        }
        return dp[n];
    }
};