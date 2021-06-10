class Solution {
public:
    int dp[1000001];
    int n;
    int solve(int i,vector<int>& arr, int d){
        if(dp[i]!=-1)
            return dp[i];
        dp[i]=0;
        for(int k=i+1;k<n && k<=i+d && arr[k]<arr[i]; k++)
            dp[i]=max(dp[i], 1+solve(k, arr,d));
        for(int k=i-1;k>=0 && k>=i-d && arr[k]<arr[i]; k--)
            dp[i]=max(dp[i], 1+solve(k, arr,d));
        return dp[i];
    }
    
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        int ans=0;
        for(int i=0;i<1001;i++)
            dp[i]=-1;
        for(int i=0;i<n;i++)
            ans=max(ans, 1+solve(i,arr,d));
        return ans;
    }
};