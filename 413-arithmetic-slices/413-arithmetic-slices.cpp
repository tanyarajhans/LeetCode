class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return 0;
        int dp[n]; //dp[i] denotes number of arithmetic slices till i
        dp[0]=0;
        dp[1]=0;
        if(nums[2]-nums[1]==nums[1]-nums[0])
            dp[2]=1;
        int ans=dp[2];
        for(int i=3;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                dp[i]=dp[i-1]+1;
            else
                dp[i]=0;
            ans+=dp[i];
        }
        return ans;
    }
};