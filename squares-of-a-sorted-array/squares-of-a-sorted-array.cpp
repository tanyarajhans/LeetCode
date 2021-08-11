class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=n-1;
        int pos=n-1;
        vector<int> ans(n);
        while(l<=r){
            if(abs(nums[l])<abs(nums[r]))
                ans[pos]=nums[r]*nums[r--];
            else
                ans[pos]=nums[l]*nums[l++];
            pos--;
        }
        return ans;
    }
};