int dp[101][101][27][101];
class Solution {
public:
    
    int solve(int ind, int l, int prev, string &s, int k){
        if(k<0)
            return INT_MAX;
        if(ind==s.size())
            return 0;
        if(dp[ind][l][prev][k]!=-1)
            return dp[ind][l][prev][k];
        
        int ans=solve(ind+1,l,prev,s,k-1); //delete 
        //keep
        int keep=0;
        if(s[ind]-'a'==prev){ //freq of prev will increase
            if(l==1 || l==9 || l==99){
                keep=1;
            }
            keep+=solve(ind+1, l+1, prev, s, k);
        }
        else{
            keep=1+solve(ind+1, 1, s[ind]-'a', s, k);
        }
        ans=min(ans, keep);
        return dp[ind][l][prev][k]=ans;
        
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,26,s,k);
    }
};



