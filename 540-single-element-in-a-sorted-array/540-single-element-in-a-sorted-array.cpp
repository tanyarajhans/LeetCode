class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,h=n-2; 
        //before:first instance - at even index, second instance at odd index
        //after: first instance - at odd index, second instance at even index
        while(l<=h){
            int mid=l+(h-l)/2;
            if((mid%2==0 && (nums[mid]==nums[mid+1]))|| (mid%2==1 && (nums[mid]==nums[mid-1])))//before and same as nums[mid]==nums[mid^1]
                l=mid+1;
            else
                h=mid-1;
        }
        return nums[l];
    }
};