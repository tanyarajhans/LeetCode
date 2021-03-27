class Solution {
public:
    string longestPalindrome(string s) {
        int m=s.size();
        int dp[m][m];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++){
            dp[i][i]=1;
        }
        int start=0,end=1;
        for(int i=0;i<m-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                start=i;
                end=2;
            }
        }
        for(int i=2;i<m;i++){
            for(int j=0;j<m-i;j++){
              if(dp[j+1][i+j-1]==1 && s[j]==s[i+j]){
                  dp[j][i+j]=1;
                  start=j;
                  end=i+1;
              }   
           }
        }
        return s.substr(start,end);
    }
};