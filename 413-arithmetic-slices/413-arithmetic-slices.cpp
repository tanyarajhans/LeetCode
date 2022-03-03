class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)
        {
            return 0;
        }
        
        int ans=0, l=0; 
        
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                l++;                  
            else
            {
                ans+=l*(l+1)/2;
                l=0;
            }
        }
        if(l)
        ans+=l*(l+1)/2;
        return ans;
    }
};