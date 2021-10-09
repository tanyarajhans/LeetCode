class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int d=-1;
        for(int i=0;i<nums.size();i++){
            int curr=abs(nums[i]);
            if(nums[curr]<0){
                d=curr;
                break;
            }
            nums[curr]*=-1;
        }
        return d;
    }
};