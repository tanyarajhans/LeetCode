class Solution {
public:
    int bs(int x, vector<int>& nums){
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<x)
                l=mid+1;
            else
                r=mid-1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int i1=bs(target, nums);
        int i2=bs(target+1, nums)-1;
        if(i1==-1)
            return {-1,-1};
        if(i1<n && nums[i1]==target)
            return {i1,i2};
        return {-1,-1};
    }
};