class Solution {
public:
    int dp[1002][1002];
    
    int solve(string s, string t, int i, int j){
        if(i==0 && j==0)
            return 1;
        if(j==0)
            return 1;
        if(i==0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i-1]==t[j-1])
           return dp[i][j]=solve(s,t,i-1,j-1)+solve(s,t,i-1,j);
        else
            return dp[i][j]=solve(s,t,i-1,j);
    }
    
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,t,n,m);
    }
};
