class Solution {
public:
    
    long long maxPoints(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        long long dp[m];
        for(int j=0;j<m;j++) //first row
            dp[j]=mat[0][j];
        for(int i=1;i<n;i++){
            long long lmax[m];
            long long rmax[m];
            for(int j=0;j<m;j++){
                lmax[j]=0;
                rmax[j]=0;
            }
            lmax[0]=dp[0];
            for(int j=1;j<m;j++){
                lmax[j]=(lmax[j-1]-1>dp[j])?lmax[j-1]-1:dp[j];
            }
            rmax[m-1]=dp[m-1];
            for(int j=m-2;j>=0;j--){
                rmax[j]=(rmax[j+1]-1>dp[j])?rmax[j+1]-1:dp[j];
            }
            for(int j=0;j<m;j++){
                dp[j]=mat[i][j]+max(lmax[j],rmax[j]);
            }
        }
        long long ans=dp[0];
        for(int i=1;i<m;i++)
            ans=(ans>dp[i])?ans:dp[i];
        return ans;
    }
};