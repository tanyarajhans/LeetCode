class Solution {
public:
    int vis[17];
    int n;
    
    bool solve(vector<int>& nums, int ind, int cs, int target, int k){
        if(k==1){
            return true;
        }
        if(ind==n){
            return false;
        }
        if(cs==target)
            return solve(nums, 0, 0, target, k-1);
        for(int i=ind;i<n;i++){
            if (i-1 >= 0 && nums[i]==nums[i-1] && !vis[i-1]) //handle TLE for consecutive same elements
                continue;
            if(!vis[i] && cs+nums[i]<=target){
                vis[i]=1;
                if(solve(nums,i+1,cs+nums[i],target,k))
                    return true;
                vis[i]=0;
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size();
        memset(vis,0,sizeof(vis));
        int sum=0;
        for(auto x: nums)
            sum+=x;
        if(k==0 || sum%k!=0)
            return false;
        int target=sum/k;
        int cs=0;
        int ind=0;
        return solve(nums, ind, cs, target, k);
    }
};