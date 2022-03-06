class Solution {
public:
    int mod=1e9+7;
    int dp[502][502];
    
    long long solve(int leftToPick, int leftToDeliver){
        if(leftToPick==0 && leftToDeliver==0)
            return 1;
        if(leftToPick<0 || leftToDeliver<0 ||leftToPick>leftToDeliver){
            return 0;
        }
        if(dp[leftToPick][leftToDeliver]!=-1)
            return dp[leftToPick][leftToDeliver];
        long long ans=0;
        ans=(ans+leftToPick*solve(leftToPick-1, leftToDeliver))%mod;
        ans=(ans+(leftToDeliver-leftToPick)*solve(leftToPick, leftToDeliver-1))%mod;
        return dp[leftToPick][leftToDeliver]=ans;
    }
    
    int countOrders(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,n);
    }
};