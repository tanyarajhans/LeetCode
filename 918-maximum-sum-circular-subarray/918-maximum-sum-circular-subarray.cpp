class Solution {
public:
    
    int maxSumSubarray(vector<int>& nums){  // Maximum Subarray Sum
        int n=nums.size();
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>maxi)
                maxi=sum;
            if(sum<0)
                sum=0;
        }
        return maxi;
    }
    
    int minSumSubarray(vector<int>& nums){  // Minimum Subarray Sum
        int n=nums.size();
        int sum=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<mini)
                mini=sum;
            if(sum>0)
                sum=0;
        }
        return mini;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int minSum=minSumSubarray(nums);
        int maxSum=maxSumSubarray(nums);
        if(maxSum>0)
            return max(maxSum, sum-minSum);
        return maxSum;
    }
};