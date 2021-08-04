class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        int ind=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target==nums[mid])
                return mid;
            else if(nums[r]<nums[mid]){
                if(target<nums[mid] && target>=nums[l])
                    r=mid-1;
                else
                    l=mid+1;
            }
            else if(nums[l]>nums[mid]){
                if(target>nums[mid] && target<=nums[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
            else{
                if(target>nums[mid])
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
        return -1;
    }
};