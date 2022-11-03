class Solution {
public:
    int trap(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        int maxl=0,maxr=0;
        int ans=0;
        while(l<r){
            if(nums[l]<=nums[r]){
                if(nums[l]>maxl){
                    maxl=nums[l];
                }
                else
                    ans+=maxl-nums[l];
                l++;
            }
            else{
                if(nums[r]>maxr){
                    maxr=nums[r];
                }
                else
                    ans+=maxr-nums[r];
                r--;
            }
        }
        return ans;
    }
};