class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=1;
        for(int i=0;i<n;i++){
            if(mini==nums[i])
                mini++;
            if(nums[i]>mini)
                break;
        }
        return mini;
    }
};
