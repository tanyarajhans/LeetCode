class Solution {
public:
    int dp[32][1005];
    int mod=1e9+7;
    
    int solve(int n,int k,int target){
        if(n==0){
            if(target==0)
                return 1;
            return 0;
        }
        if(target<0)
            return 0;
        if(n*k<target)
            return 0;
        if(n*k==target)
            return 1;
        if(dp[n][target]!=-1)
            return dp[n][target];
        long long ans=0;
        for(int i=1;i<=k;i++){
            ans=(ans+solve(n-1,k,target-i))%mod;
        }
        return dp[n][target]=ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        if(k*n<target)
            return 0;
        if(k*n==target)
            return 1;
        memset(dp,-1,sizeof(dp));
        return solve(n,k,target);
    }
};