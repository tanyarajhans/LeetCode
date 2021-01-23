class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1) 
            return (nums[0]==target);
        int l=0, r=n-1; 
        while(l<=r){
            while(r>l && nums[r]==nums[l])
                r--;
            int mid=(r+l)/2;
            if(nums[mid]==target)
                return true;
            else if(nums[l]<=nums[mid]){
                if(nums[l]<=target && target<nums[mid]) 
                    r=mid-1;
                else 
                    l=mid+1;
            }
            else{
                if(nums[mid]<target && target<=nums[r]) 
                    l=mid+1;
                else 
                    r=mid-1;
            }
        }
        return false;
    }
};
