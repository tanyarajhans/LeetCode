class Solution {
public:
    int dp[22][22];
    
    int solve(int i, int j, vector<int>& nums){ //solving max score for p1
        if(i>j)
            return 0;
        if(i==j)
            return nums[i];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int x=max(nums[i]+min(solve(i+2, j, nums), solve(i+1,j-1,nums)), nums[j]+min(solve(i+1, j-1, nums), solve(i, j-2, nums)));
        return dp[i][j]=x;
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(auto x: nums)
            total+=x;
        memset(dp,-1,sizeof(dp));
        int p1=solve(0, n-1, nums);
        return p1>=total-p1;
    }
};