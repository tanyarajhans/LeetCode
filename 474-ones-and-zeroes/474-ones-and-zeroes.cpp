class Solution {
public:
    int sz;
    int dp[601][102][102];
    
    int solve(int ind, int z, int o, vector<string>& strs, int m, int n){
        if(ind==sz || z>m || o>n)
            return 0;
        if(dp[ind][z][o]!=-1)
            return dp[ind][z][o];
        int ans=0;
        int zz=0,oo=0;
        for(int i=0;i<strs[ind].size();i++){
            if(strs[ind][i]=='0')
                zz++;
            else oo++;
        }
        if(z+zz<=m && o+oo<=n){
            ans=max(1+solve(ind+1, z+zz, o+oo, strs,m,n), solve(ind+1, z, o, strs,m,n));
        }
        else
            ans=solve(ind+1, z, o, strs,m,n);
        return dp[ind][z][o]=ans;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        sz=strs.size();
        memset(dp,-1,sizeof(dp));
        int z=0,o=0;
        return solve(0, z, o, strs, m, n);
    }
};