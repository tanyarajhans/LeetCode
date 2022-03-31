class Solution {
public:
    int pre[1005];
    int dp[1005][52];
    int ans;
    int n;
    
    int solve(int ind, vector<int>& nums, int m){
        if(ind==n && m==0)
            return 0;
        if(ind==n || m==0)
            return INT_MAX;
        if(dp[ind][m]!=-1)
            return dp[ind][m];
        int ans=INT_MAX;
        for(int i=ind;i<n;i++){
            int curr=pre[i]-((ind-1>=0)?pre[ind-1]:0);
            int nxt=solve(i+1, nums,m-1);
            ans=min(ans, max(curr, nxt));
        }
        return dp[ind][m]=ans;
    }
    
    int splitArray(vector<int>& nums, int m) {
        n=nums.size();
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        memset(dp,-1,sizeof(dp));
        int ind=0;
        int st=0;
        return solve(ind, nums, m);
    }
};