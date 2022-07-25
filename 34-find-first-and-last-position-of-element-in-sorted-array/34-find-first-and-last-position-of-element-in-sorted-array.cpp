class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        int p1=-1,p2=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                p1=mid;
                r=mid-1;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else
                l=mid+1;
        }
        l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>=target+1){
                r=mid-1;
            }
            else{
                
                l=mid+1;
            }
                
        }
        p2=l;
        if(p1!=-1)
        return {p1,p2-1};
        return {-1,-1};
    }
};