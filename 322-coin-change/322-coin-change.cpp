class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[amount+1];
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int v=INT_MAX-1;
            for(int j=0;j<n;j++){
                if(coins[j]<=i && dp[i-coins[j]]!=INT_MAX-1)
                    v=min(v, dp[i-coins[j]]+1);
            }
            dp[i]=v;
           // cout<<dp[i]<<" ";
        }
        return dp[amount]==INT_MAX-1?-1:dp[amount];
    }
};