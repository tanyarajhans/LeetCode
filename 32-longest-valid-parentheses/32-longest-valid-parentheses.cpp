class Solution {
public:
    int dp[30005]; //dp[i]=longest valid parentheses till index i
    int longestValidParentheses(string s) {
        int n=s.size();
        memset(dp,0,sizeof(dp));
        if(n==0 || n==1)
            return 0;
        // for(int i=1;i<n;i++){
        //     if(s[i]==')'){
        //         if(s[i-1]=='('){
        //             dp[i]=2+(i-2>=0?dp[i-2]:0);
        //         }
        //         else if((i-dp[i-1]-1>=0) && s[i-dp[i-1]-1]=='('){
        //             dp[i]=2+dp[i-1]+((i-dp[i-1])>=2?dp[i-dp[i-1]-2]:0);
        //         }
        //     }
        // }
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     ans=max(ans,dp[i]);
        // }
        int ans=0;
        int o=0,c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                o++;
            else
                c++;
            if(o==c)
                ans=max(ans, 2*c);
            else if(c>o)
                o=c=0;
        }
        o=c=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(')
                o++;
            else
                c++;
            if(o==c)
                ans=max(ans, 2*c);
            else if(o>c)
                o=c=0;
        }
        return ans;
    }
};