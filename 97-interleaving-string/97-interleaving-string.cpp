class Solution {
public:
    int n,m,sz;
    int dp[101][101][201];
    
    bool solve(int i, int j, int ind, string s1, string s2, string s3){
        if(ind==sz && i>=n && j>=m)
            return true;
        if(dp[i][j][ind]!=-1)
            return dp[i][j][ind];
        bool ans=false;
        if(s1[i]==s3[ind])
            ans=ans|solve(i+1,j,ind+1,s1,s2,s3);
        if(s2[j]==s3[ind])
            ans=ans|solve(i,j+1,ind+1,s1,s2,s3);
        return dp[i][j][ind]=ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size();
        m=s2.size();
        sz=s3.size();
        memset(dp,-1,sizeof(dp));
        if(n+m!=sz)
            return false;
        return solve(0,0,0,s1,s2,s3);
    }
};