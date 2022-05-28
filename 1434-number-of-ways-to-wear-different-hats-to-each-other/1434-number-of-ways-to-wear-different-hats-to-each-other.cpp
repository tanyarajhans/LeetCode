class Solution {
public:
    //use a mask to denote people as 2^10*40 won't TLE
    //dp(h, mask) will denote whether h mask will be assigned to a person or not
    
    map<int,set<int>> m;
    vector<int> hs;
    int n;
    int dp[41][1<<11];
    int mod=1e9+7;
    
    long long solve(int ind, int people){
        if(people==((1<<n)-1))
            return 1;
        if(ind==hs.size())
            return 0;
        if(dp[ind][people]!=-1)
            return dp[ind][people];
        long long v=solve(ind+1,people)%mod;
        int hat=hs[ind];
        for(int i=0;i<n;i++){
            if(((people&(1<<i))==0) && m[hat].find(i)!=m[hat].end()){
                v=(v+(long long)solve(ind+1,(people^(1<<i))))%mod;
            }
        }
        return dp[ind][people]=(int)v;
    }
    
    
    
    int numberWays(vector<vector<int>>& hats) {
        n=hats.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<hats[i].size();j++){
               m[hats[i][j]].insert(i);
            }
        }
        for(auto it: m){
            hs.push_back(it.first);
        }
        return solve(0,0);
    }
};