class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        int l=0, r=n-2;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==nums[mid^1])  
                l=mid+1;
            else
                r=mid-1;
        }
        return nums[l];
    }
};