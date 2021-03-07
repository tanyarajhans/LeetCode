class Solution {
public:
    int ans=0;
    
    void backtrack(int i, vector<int>& nums, long long sum, int S){
        if(i==nums.size()){
            if(S==sum)
            ans++;
        }
        else{
            backtrack(i+1, nums, sum+nums[i], S);
            backtrack(i+1, nums, sum-nums[i], S);
        }
        
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        backtrack(0, nums, 0, S);
        return ans;
    }
};