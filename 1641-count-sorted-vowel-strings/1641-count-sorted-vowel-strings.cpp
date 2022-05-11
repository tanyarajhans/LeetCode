class Solution {
public:
    int countVowelStrings(int n) {
        int dp[n][5];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<5;i++){
            dp[0][i]=1; //string of size 1
        }
        for(int i=1;i<n;i++){ //i length
            for(int j=0;j<5;j++){ //starting with j
                for(int k=j;k<5;k++){
                    dp[i][j]+=dp[i-1][k];
                }
            }
        }
        int ans=0;
        for(int i=0;i<5;i++){
            ans+=dp[n-1][i];
        }
        return ans;
    }
};