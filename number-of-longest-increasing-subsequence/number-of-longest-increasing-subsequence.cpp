class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 1;
        int dp[n];
        int count[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
            count[i]=1;
        }
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(dp[j]+1>dp[i] && nums[j]<nums[i]){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if(dp[j]+1==dp[i] && nums[j]<nums[i])
                    count[i]+=count[j];
            }
        }
        for(int i=0;i<n;i++)
            ans=max(ans, dp[i]);
        int c=0;
        for(int i=0;i<n;i++){
            if(ans==dp[i])
                c+=count[i];
        }
        return c;
    }
};