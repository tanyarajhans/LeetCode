class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c=0, ans=-1;
        for(int i=0;i<n;i++){
            if(c==0)
                ans=nums[i];
            if(nums[i]==ans){
                c++;
            }
            else c--;
        }
        return ans;
    }
};