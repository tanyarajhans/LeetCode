class Solution {
public:
    int mod=1e9+7;
    int dp[502][502];
    int n;
    
    long long solve(int leftToPick, int leftToDeliver){
        if(leftToPick==0 && leftToDeliver==0)
            return 1;
        if(leftToPick<0 || leftToDeliver<0){
            return 0;
        }
        if(dp[leftToPick][leftToDeliver]!=-1)
            return dp[leftToPick][leftToDeliver];
        long long ans=0;
        ans=(ans+leftToPick*solve(leftToPick-1, leftToDeliver+1))%mod; //choose one to pick up, then we get to deliver it as well
        ans=(ans+leftToDeliver*solve(leftToPick, leftToDeliver-1))%mod; //choose one to deliver
        return dp[leftToPick][leftToDeliver]=ans;
    }
    
    int countOrders(int n) {
        n=n;
        memset(dp,-1,sizeof(dp));
        return solve(n,0); //we have n pick up choices and 0 delivery choices initially
    }
};