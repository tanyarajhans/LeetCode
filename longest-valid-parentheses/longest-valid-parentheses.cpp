class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        if(n==0)
            return 0;
        int dp[n];  // dp[i] denotes longestValidParentheses till i
        int ans=0;
        for(int i=0;i<n;i++)
            dp[i]=0;
        for(int i=1;i<n;i++){
            if(s[i]=='(')
                dp[i]=0;
            else{
                if(s[i-1]=='('){
                    if(i>=2){
                        dp[i]=dp[i-2]+2;
                    }
                    else
                        dp[i]=2;
                }
                else if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='('){
                    if(i-dp[i-1]>=2)
                        dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2;
                    else
                        dp[i]=dp[i-1]+2;   
                }
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};