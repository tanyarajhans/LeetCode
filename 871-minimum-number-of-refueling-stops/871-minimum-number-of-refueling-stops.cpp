class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n=stations.size();
        long dp[n+1]; //dp[i] denotes max distance we can cover by using this station as refueling station
        memset(dp,0,sizeof(dp));
        dp[0]=startFuel;
        for(int i=0;i<n;i++){
            for(int j=i;j>=0 && dp[j]>=stations[i][0];j--){
                dp[j+1]=max(dp[j+1], dp[j]+stations[i][1]);
            }
        }
        for(int i=0;i<=n;i++){
            if(dp[i]>=target)
                return i;
        }
        return -1;
    }
};