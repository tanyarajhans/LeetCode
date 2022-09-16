class Solution {
public:
    int n,m;
    int dp[1005][1005];
    
    int solve(int l, vector<int>& nums, int ind, vector<int>& mul){
        if(ind==m)
            return 0;
        if(dp[l][ind]!=INT_MIN)
            return dp[l][ind];
        int ans=0;
        ans=max(nums[l]*mul[ind]+solve(l+1,nums,ind+1,mul), nums[n-(ind-l)-1]*mul[ind]+solve(l, nums,ind+1,mul));
        return dp[l][ind]=ans;
    }
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        n=nums.size();
        m=mul.size();
        for(int i = 0; i < 1005; i++) 
            for(int j = 0; j < 1005; j++)
                dp[i][j] = INT_MIN;
        return solve(0, nums, 0, mul);
    }
};