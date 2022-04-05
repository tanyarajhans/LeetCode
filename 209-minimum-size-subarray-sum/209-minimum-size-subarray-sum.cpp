class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int ans=INT_MAX;
        int i=0,j=0;
        while(j<n){
            s+=nums[j];
            if(s>=target){
                ans=min(ans, j-i+1);
            }
            while(i<j && s>=target){
                s-=nums[i];
                i++;
                if(s>=target)
                    ans=min(ans,j-i+1);
            }
            j++;
        }
        while(i<j && s>=target){
            s-=nums[i];
            i++;
            if(s>=target)
                ans=min(ans,j-i+1);
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};