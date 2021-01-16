class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
            return 0;
        int p=1,ans=0,l=0,r=0,n=nums.size();
        for(r=0;r<n;r++){
            p*=nums[r];
            while(p>=k)
                p=p/nums[l++];
            ans+=r-l+1;
        }
        return ans;
    }
};
