class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int l[n];
        int r[n];
        
        for(int i=0;i<n;i++){
            l[i]=0;
            r[i]=0;
        }
        l[0]=nums[0];
        r[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
          l[i]=min(l[i-1], nums[i]);
        
        for(int i=n-2;i>=0;i--)
          r[i]=max(r[i+1], nums[i]);
        
        for(int i=1;i<n-1;i++){
            if(nums[i]>l[i] && nums[i]<r[i])
                return true;
        }
        return false;
    }
};