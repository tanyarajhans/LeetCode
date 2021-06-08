class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i]=1;
        if(n==1)
            return 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(nums[j]<nums[i] && dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,dp[i]);
        return ans;
    }
};