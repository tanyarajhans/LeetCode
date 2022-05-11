class Solution {
public:
    int dp[5][51];
    
    int solve(int v, int size, int n){
        if(size==n)
            return 1;
        if(v==5)
            return 0;
        if(dp[v][size]!=-1)
            return dp[v][size];
        return dp[v][size]=solve(v,size+1,n)+solve(v+1,size,n);
    }
    
    int countVowelStrings(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n);
    }
};