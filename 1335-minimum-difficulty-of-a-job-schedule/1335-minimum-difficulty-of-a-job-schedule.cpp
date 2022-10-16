class Solution {
public:
    int n;
    int dp[301][11];
    
    int solve(int i, int d, vector<int>& jd){
        if(i==n && d==0)
            return 0;
        if(i==n || d==0)
            return 1e7;
        if(dp[i][d]!=-1)
            return dp[i][d];
        
        int curr = jd[i];
        int ans = jd[i]+solve(i+1,d-1,jd);
        
        for(int j=i+1;j<n;j++){
            curr = max(curr,jd[j]);
            ans = min(ans,solve(j+1,d-1,jd)+curr);
        }
        
        return dp[i][d] = ans;
    }
    
    int minDifficulty(vector<int>& jd, int d) {
        n = jd.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,d,jd);
        return ans>=1e7 ? -1 : ans;
    }
};