class Solution {
public:
    int n;
    int dp[301];
    
    bool solve(int ind, string &s, vector<string>& w){
        if(ind==n)
            return true;
        if(dp[ind]!=-1)
            return dp[ind];
        for(int i=ind;i<n;i++){
            string v=s.substr(ind,i-ind+1);
            if(find(w.begin(), w.end(), v)!=w.end()){
                if(solve(i+1,s,w))
                    return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    
    bool wordBreak(string s, vector<string>& w) {
        n=s.size();
        int ind=0;
        memset(dp,-1,sizeof(dp));
        return solve(ind, s, w);
    }
};