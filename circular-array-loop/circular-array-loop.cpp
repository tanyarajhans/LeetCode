class Solution {
public:
    
    int next(vector<int>& nums, int idx, bool dir){
        bool x=(nums[idx]>=0);
        if(x!=dir)
            return INT_MIN;
        int n=nums.size();
        int v=(idx+nums[idx])%n;
        if(v<0){
           v=v+nums.size();
        }
        if(v==idx)
            return INT_MIN;
        return v;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()<2)
           return false;
        for(int i=0;i<n;i++){
            int slow=i,fast=i;
            bool dir=nums[i]>0;
            while(true){
                slow=next(nums,slow,dir);
                if(slow==INT_MIN)
                    break;
                fast=next(nums,fast,dir);
                if(fast==INT_MIN)
                    break;
                fast=next(nums,fast,dir);
                if(fast==INT_MIN)
                    break;
                if(slow==fast)
                    return true;
            }
        }
        return false;
    }
};
