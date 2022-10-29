class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int ans;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        return max({nums[n-1]*nums[n-2]*nums[n-3], nums[n-1]*nums[n-2]*nums[0], nums[n-1]*nums[0]*nums[1]});
    }
};