class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        return pre;
    }
};