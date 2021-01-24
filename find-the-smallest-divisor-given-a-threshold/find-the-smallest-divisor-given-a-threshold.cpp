class Solution {
public:
    
    bool isValid(vector<int>& nums, int t, int mid){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i]/mid;
            int y=nums[i]%mid;
            if(y>0)
                x++;
            ans+=x;
        }
        if(ans<=t)
            return true;
        return false;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=1;
        for(int i=0;i<nums.size();i++)
            r=max(r,nums[i]);
        while(l<r){
            int mid=l+(r-l)/2;
            if(isValid(nums,threshold,mid)){
                r=mid;
            }
            else
                l=mid+1;
        }
        return l;
    }
};
