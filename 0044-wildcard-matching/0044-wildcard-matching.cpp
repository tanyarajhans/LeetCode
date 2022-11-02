class Solution {
public:
    bool solve(int i, int j , string &s, string &p, vector<vector<int>>&dp){
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){    // check if all stars or not
            for(int idx = j; j>=0 ;j--){
                if(p[j]!='*'){
                    return false;
                }
            }
            return true;
        }   
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] = solve(i-1,j-1,s,p,dp);
        }
        else if(p[j]=='*'){
            return dp[i][j] = solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp); 
            
            /** 
            1. replace ‘*’ with nothing and act as if it was not present. i.e. f(i-1,j)
            2. replace ‘*’ with a single character at index j and make the i pointer to 
               still point at index i i.e. f(i,j-1).
               we matched it with a single character (one of the many options that need to be tried)
               and in the next recursive call, as i still point to ‘*’, we get the exact two 
               recursive calls again.
               
            **/
        }
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
         int n = s.size(), m = p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,s,p,dp);
    }
};