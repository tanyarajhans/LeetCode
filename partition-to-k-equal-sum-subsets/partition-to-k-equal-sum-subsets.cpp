class Solution {
public:
    bool used[17];
    
    bool solve(int idx, int currsum, vector<int>& nums, int k, int onesum, int n){
        if(k==1)
            return true;
        if(currsum>onesum)
            return false;
        if(currsum==onesum)
            return solve(0, 0, nums, k-1, onesum, n);
        for(int i=idx; i<n;i++){
            if(!used[i])
            {
                used[i]=true;
                if(solve(idx+1, currsum+nums[i], nums, k, onesum, n))
                    return true;
                used[i]=false;
            }
        }
        return false;
    }
    
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;i++){
           s+=nums[i]; 
        }
        if(k==0 || s%k!=0)
            return false;
        return solve(0, 0, nums, k, s/k, n);
    }
};
